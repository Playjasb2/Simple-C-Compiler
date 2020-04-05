//
// Created by Jasmeet Brar on 2020-01-12.
//

#include <string>
#include <iostream>
#include <utility>

#include <algorithm>

#include "tokenizer.h"

using namespace std;

tokenizer::tokenizer() {
    this->token_stream = new vector<Token>;
}

void tokenizer::add_token_to_stream(Token_Type type) {
    Token new_token;
    new_token.type = type;
    new_token.line_number = this->line_number;
    new_token.position_number = this->position_number;
    new_token.value = this->current_word;

    this->token_stream->push_back(new_token);
}

void tokenizer::process_file(string filename) {
    current_stream_name = move(filename);
    current_stream.open(current_stream_name);

    if(current_stream.is_open()) {
        read_current_file();
    }
    else {
        print("Cannot open " + current_stream_name);
    }

}

void tokenizer::read_current_file() {
    string line;

    line_number = 0;

    while(getline(current_stream, line)) {

        line_number++;
        position_number = 1;

        line_char = line.c_str();

        while(*line_char != '\0') {
            if(inComment) {
                this->continue_to_read_comment();
            }
            else if(*line_char == ' ' || *line_char == '\t') {
                line_char++;
                position_number++;
            }
            else if(isalpha(*line_char) || *line_char == '_') {
                this->read_identifier();
            }
            else if(isdigit(*line_char)) {
                this->read_number();
            }
            else if(*line_char == '/' && *(line_char + 1) == '/') {
                break;
            }
            else if(*line_char == '/' && *(line_char + 1) == '*') {
                this->read_comment();
            }
            else if(*line_char == '+' || *line_char == '-' || *line_char == '*'
            || *line_char == '/' || *line_char == '=' || *line_char == '&'
            || *line_char == '|' || *line_char == '<' || *line_char == '>'
            || *line_char == '!' || *line_char == '%') {
                this->read_symbol();
            }
            else if(*line_char == '"') {
                line_char++;
                this->read_string();
            }
            else if(*line_char == '{') {
                current_word += *line_char;
                this->add_token_to_stream(Token_Type::left_curly_bracket);
                current_word = "";
                line_char++;
                position_number++;
            }
            else if(*line_char == '}') {
                current_word += *line_char;
                this->add_token_to_stream(Token_Type::right_curly_bracket);
                current_word = "";
                line_char++;
                position_number++;
            }
            else if(*line_char == '(') {
                current_word += *line_char;
                this->add_token_to_stream(Token_Type::left_round_bracket);
                current_word = "";
                line_char++;
                position_number++;
            }
            else if(*line_char == ')') {
                current_word += *line_char;
                this->add_token_to_stream(Token_Type::right_round_bracket);
                current_word = "";
                line_char++;
                position_number++;
            }
            else if(*line_char == ';') {
                current_word += *line_char;
                this->add_token_to_stream(Token_Type::semicolon);
                current_word = "";
                line_char++;
                position_number++;
            }
            else {
                this->read_invalid_token();
            }
        }
    }
    current_word = "eof";
    this->add_token_to_stream(Token_Type::eof);
}

void tokenizer::read_symbol() {
    vector<char> symbols = {'+', '-', '*', '/', '%', '<', '>', '=', '!', '&', '|'};

    while(*line_char != '\0') {
        if(find(symbols.begin(), symbols.end(), *line_char) != symbols.end()) {
            current_word += *line_char;
            line_char++;
        }
        else {
            break;
        }
    }

    if(symbol_to_type.find(current_word) == keyword_to_token_type.end()) {
        this->add_token_to_stream(Token_Type::invalid);
    }
    else {
        this->add_token_to_stream(symbol_to_type[current_word]);
    }

    position_number += current_word.length();
    current_word = "";
}

bool tokenizer::read_keyword_if_any() {
    if(keyword_to_token_type.find(current_word) == keyword_to_token_type.end()) {
        return false;
    }
    else {
        auto current_type = keyword_to_token_type[current_word];

        if(current_type == Token_Type::if_ && token_stream->back().type == Token_Type::else_) {
            token_stream->pop_back();
            this->current_word = "else if";
            this->add_token_to_stream(Token_Type::else_if_);
        }
        else {
            this->add_token_to_stream(current_type);
        }

        return true;
    }
}

void tokenizer::read_identifier() {
    while(*line_char != '\0') {
        if(isalnum(*line_char) || *line_char == '_') {
            current_word += *line_char;
            line_char++;
        }
        else {
            break;
        }
    }

    if(!this->read_keyword_if_any()){
        this->add_token_to_stream(Token_Type::identifier);
    }

    position_number += current_word.length();
    current_word = "";
}

void tokenizer::read_number() {
    while(*line_char != '\0') {
        if(isdigit(*line_char)) {
            current_word += *line_char;
            line_char++;
        }
        else {
            break;
        }
    }

    this->add_token_to_stream(Token_Type::integer);

    position_number += current_word.length();
    current_word = "";
}

void tokenizer::read_comment() {
    line_char += 2;
    position_number += 2;

    inComment = true;

    this->continue_to_read_comment();
}

void tokenizer::continue_to_read_comment() {
    while(*line_char != '\0') {
        if(*line_char == '*' && *(line_char + 1) == '/') {
            inComment = false;
            line_char += 2;
            position_number += 2;
            break;
        }
        line_char++;
        position_number++;
    }
}

void tokenizer::read_string() {
    bool gotEndQuote = false;

    while(*line_char != '\0') {
        if(*line_char == '"') {
            gotEndQuote = true;
            break;
        }
        else if(*line_char == '\\' && *(line_char + 1) == '"') {
            current_word += "\"";
            line_char += 2;
        }
        else {
            current_word += *line_char;
            line_char++;
        }
    }

    if(gotEndQuote) {
        this->add_token_to_stream(Token_Type::string);
    }
    else {
        this->add_token_to_stream(Token_Type::invalid);
    }

    line_char++;
    position_number += current_word.length() + 3;
    current_word = "";
}

void tokenizer::read_invalid_token() {
    while(*line_char != '\0' || *line_char != ' ' || *line_char != '\t') {
        current_word += *line_char;
        line_char++;
    }

    this->add_token_to_stream(Token_Type::invalid);
    position_number += current_word.length();
    current_word = "";
}

tokenStream *tokenizer::get_token_stream() {
    if(token_stream->empty()){
        return nullptr;
    }
    else {
        return new tokenStream(token_stream);
    }
}

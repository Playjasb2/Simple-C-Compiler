//
// Created by Jasmeet Brar on 2020-01-12.
//

#include <string>
#include <iostream>
#include <utility>
#include <map>

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
        print(line);

        line_number++;
        position_number = 1;

        line_char = line.c_str();

        while(*line_char != '\0') {
            if(inComment) {
                this->read_comment();
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
            || *line_char == '(' || *line_char == ')' || *line_char == '!'
            || *line_char == '%') {
                this->read_symbol();
            }
            else if(*line_char == '"') {
                this->read_string();
            }
            else if(*line_char == '{') {
                this->add_token_to_stream(Token_Type::left_curly_bracket);
            }
            else if(*line_char == '}') {
                this->add_token_to_stream(Token_Type::right_curly_bracket);
            }
            else if(*line_char == '(') {
                this->add_token_to_stream(Token_Type::left_round_bracket);
            }
            else if(*line_char == ')') {
                this->add_token_to_stream(Token_Type::right_round_bracket);
            }
            else if(*line_char == ';') {
                this->add_token_to_stream(Token_Type::semicolon);
            }
            else {
                this->read_invalid_token();
            }

            line_char++;
            position_number++;
        }
    }
}

bool tokenizer::read_keyword_if_any() {
    map<string, Token_Type> keyword_to_token_type
    = {{"if" , Token_Type::if_},
       {"else", Token_Type::else_},
       {"int", Token_Type::int_type_keyword}};

    if(keyword_to_token_type.find(current_word) == keyword_to_token_type.end()) {
        return false;
    }
    else {
        this->add_token_to_stream(keyword_to_token_type[current_word]);
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

    position_number += current_word.length() - 1;
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

    position_number += current_word.length() - 1;
    current_word = "";
}

void tokenizer::read_comment() {
    line_char += 2;
    position_number += 2;

    inComment = true;

    while(*line_char != '\0' && *line_char != '*' && *(line_char + 1) != '/') {
        line_char++;
        position_number++;
    }

    line_char += 2;
    position_number += 2;
    inComment = false;
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

    position_number += current_word.length() - 1;
    current_word = "";
}

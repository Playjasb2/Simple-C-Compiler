//
// Created by Jasmeet Brar on 2020-01-12.
//

#include <string>
#include <iostream>
#include <utility>

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

            if(isalpha(*line_char) || *line_char == '_') {
                this->read_identifier();
            }
            else if(isdigit(*line_char)) {
                this->read_number();
            }
            else if(*line_char == '/' && (*(line_char + 1) == '/' || *(line_char + 1) == '*')) {
                this->read_comment();
            }
            else if(*line_char == '+' || *line_char == '-' || *line_char == '*'
            || *line_char == '/' || *line_char == '=' || *line_char == '&'
            || *line_char == '|' || *line_char == '<' || *line_char == '>'
            || *line_char == '(' || *line_char == ')') {
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

    if(current_word == "int") {
        this->add_token_to_stream(Token_Type::int_type_keyword);
    }
    else {
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

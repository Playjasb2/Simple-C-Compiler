//
// Created by Jasmeet Brar on 2020-01-12.
//

#ifndef COMPILER_PROJECT_TOKENIZER_H
#define COMPILER_PROJECT_TOKENIZER_H

#endif //COMPILER_PROJECT_TOKENIZER_H

#include <string>
#include <iostream>
#include <fstream>

#include <tokenStream.h>
#include <print.h>

using namespace std;

class tokenizer {

private:

    unsigned int line_number = 0;
    unsigned int position_number = 0;
    const char *line_char = nullptr;
    string current_word;
    string current_stream_name;
    ifstream current_stream;

    bool inComment = false;

    vector<Token> *token_stream;

    void add_token_to_stream(Token_Type type);

    bool read_keyword_if_any();

    void read_current_file();
    void read_identifier();
    void read_number();
    void read_symbol();
    void read_string();
    void read_comment();
    void read_invalid_token();

public:
    tokenizer();
    void process_file(string filename);
};
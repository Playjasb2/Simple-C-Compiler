//
// Created by Jasmeet Brar on 2020-01-12.
//

#ifndef COMPILER_PROJECT_TOKENIZER_H
#define COMPILER_PROJECT_TOKENIZER_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>

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

    map<string, Token_Type> keyword_to_token_type
    = {{"if" , Token_Type::if_},
       {"else", Token_Type::else_},
       {"int", Token_Type::int_type_keyword}};

    map<string, Token_Type> symbol_to_type
    = {{"+", Token_Type::plus},
       {"-", Token_Type::minus},
       {"*", Token_Type::multiply},
       {"/", Token_Type::divide},
       {"++", Token_Type::plus_plus},
       {"--", Token_Type::minus_minus},
       {"+=", Token_Type::plus_equal},
       {"-=", Token_Type::minus_equal},
       {"*=", Token_Type::multiply_equal},
       {"/=", Token_Type::divide_equal},
       {"=", Token_Type::equal},
       {"==", Token_Type::equal_equal},
       {"&&", Token_Type::and_},
       {"||", Token_Type::or_},
       {"!", Token_Type::not_},
       {"!=", Token_Type::not_equal},
       {"%", Token_Type::modulo},
       {">", Token_Type::greater_than},
       {"<", Token_Type::less_than},
       {">=", Token_Type::greater_than_or_equal_to},
       {"<=", Token_Type::less_than_or_equal_to}};

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
    void continue_to_read_comment();
    void read_invalid_token();

public:
    tokenizer();
    void process_file(string filename);
    tokenStream *get_token_stream();
};

#endif //COMPILER_PROJECT_TOKENIZER_H
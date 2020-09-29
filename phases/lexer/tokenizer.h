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

class tokenizer {

private:

    unsigned int line_number = 0;
    unsigned int position_number = 0;

    unsigned int last_line_number;
    unsigned int last_position_number;

    const char *line_char = nullptr;
    std::string current_word;
    std::string current_stream_name;
    std::ifstream current_stream;

    std::map<std::string, Token_Type> keyword_to_token_type
    = {{"if" , Token_Type::if_},
       {"else", Token_Type::else_},
       {"int", Token_Type::int_type_keyword}};

    std::map<std::string, Token_Type> symbol_to_type
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

    std::vector<Token> *token_stream;

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

    void advance_to_next_character();

public:
    tokenizer();
    void process_file(std::string filename);
    tokenStream *get_token_stream();


};

#endif //COMPILER_PROJECT_TOKENIZER_H
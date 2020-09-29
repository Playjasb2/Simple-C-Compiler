//
// Created by Jasmeet Brar on 2020-01-03.
//

#ifndef JAS_COMPILER_TOKEN_H
#define JAS_COMPILER_TOKEN_H

#include <string>

enum class Token_Type {
    integer = 1,
    string,
    identifier,
    semicolon,
    if_,
    else_if_,
    else_,
    and_,
    or_,
    not_,
    equal,
    plus,
    minus,
    multiply,
    divide,
    modulo,
    plus_plus,
    minus_minus,
    plus_equal,
    minus_equal,
    multiply_equal,
    divide_equal,
    equal_equal,
    not_equal,
    greater_than,
    less_than,
    greater_than_or_equal_to,
    less_than_or_equal_to,
    bitwise_and,
    bitwise_or,
    bitwise_not,
    bitwise_xor,
    bitwise_and_equal,
    bitwise_or_equal,
    bitwise_not_equal,
    bitwise_xor_equal,
    left_shift,
    right_shift,
    left_round_bracket,
    right_round_bracket,
    left_curly_bracket,
    right_curly_bracket,
    int_type_keyword,
    invalid,
    eof
};

const unsigned int number_of_token_types = (const unsigned int) Token_Type::eof;

typedef struct Token {
    unsigned int line_number;
    unsigned int position_number;
    Token_Type type;
    std::string value;
} Token;

#endif //JAS_COMPILER_TOKEN_H
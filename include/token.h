//
// Created by Jasmeet Brar on 2020-01-03.
//

#ifndef JAS_COMPILER_TOKEN_H
#define JAS_COMPILER_TOKEN_H

#endif //JAS_COMPILER_TOKEN_H

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
    symbol,
    left_curly_bracket,
    right_curly_bracket,
    int_type_keyword,
    invalid
};

using namespace std;

typedef struct Token {
    unsigned int line_number;
    unsigned int position_number;
    Token_Type type;
    string value;
} Token;
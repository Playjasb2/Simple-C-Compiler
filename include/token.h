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
    int_type_keyword
};

using namespace std;

typedef struct Token {
    int line_number;
    int position_number;
    Token_Type type;
    string value;
} Token;
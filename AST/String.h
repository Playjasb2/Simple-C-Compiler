//
// Created by Jasmeet Brar on 2020-09-24.
//

#ifndef SIMPLE_C_COMPILER_STRING_H
#define SIMPLE_C_COMPILER_STRING_H

#include "Expression.h"

using namespace AST;

namespace AST {

    class String : public Expression {

    private:
        std::string value;
        Token *token;

    public:
        explicit String(std::string value, Token *token);
    };

}


#endif //SIMPLE_C_COMPILER_STRING_H

//
// Created by Jasmeet Brar on 2020-09-24.
//

#ifndef SIMPLE_C_COMPILER_INTEGER_H
#define SIMPLE_C_COMPILER_INTEGER_H

#include "Expression.h"

using namespace AST;

namespace AST {

    class Integer : public Expression {
    private:
        Token *token;

    public:
        explicit Integer(Token *token);
        std::string getValue();
    };

}


#endif //SIMPLE_C_COMPILER_INTEGER_H

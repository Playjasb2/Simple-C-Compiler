//
// Created by Jasmeet Brar on 2020-09-24.
//

#ifndef SIMPLE_C_COMPILER_VARIABLE_H
#define SIMPLE_C_COMPILER_VARIABLE_H

#include "Expression.h"
#include "Types.h"

using namespace AST;

namespace AST {

    class Variable : public Expression {

    private:
        Type type;
        string name;
        Token *token;

    public:
        explicit Variable(string name, Type type, Token *token);
    };
}


#endif //SIMPLE_C_COMPILER_VARIABLE_H

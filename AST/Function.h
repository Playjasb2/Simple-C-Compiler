//
// Created by Jasmeet Brar on 2020-09-24.
//

#ifndef SIMPLE_C_COMPILER_FUNCTION_H
#define SIMPLE_C_COMPILER_FUNCTION_H

#include "Expression.h"
#include "Types.h"

using namespace AST;

namespace AST {

    class Function : public Expression {
    private:
        Type type;
        string name;
        Token *token;

    public:
        Function(string name, Type type, Token *token);
    };

}


#endif //SIMPLE_C_COMPILER_FUNCTION_H

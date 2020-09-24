//
// Created by Jasmeet Brar on 2020-09-24.
//

#ifndef SIMPLE_C_COMPILER_NULLEXPRESSIONSTATEMENT_H
#define SIMPLE_C_COMPILER_NULLEXPRESSIONSTATEMENT_H

#include "Expression.h"
#include "Statement.h"

using namespace AST;

namespace AST {

    class NullExpressionStatement : public Expression, public Statement {

    public:
        NullExpressionStatement() = default;

    };
}


#endif //SIMPLE_C_COMPILER_NULLEXPRESSIONSTATEMENT_H

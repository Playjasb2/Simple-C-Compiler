//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_INCREMENTDECREMENTEXPRESSION_H
#define SIMPLE_C_COMPILER_INCREMENTDECREMENTEXPRESSION_H


#include "UnaryExpression.h"
#include "VariableStatement.h"

namespace AST {

    enum IncrementDecrementOperator {
        plus_plus_prefix = 1,
        plus_plus_postfix,
        minus_minus_prefix,
        minus_minus_postfix
    };

    class IncrementDecrementExpression : public UnaryExpression, public VariableStatement {

    private:
        IncrementDecrementOperator op;
        bool isStatement;

    public:
        IncrementDecrementExpression(Variable *variable, IncrementDecrementOperator op, bool isStatement);
        void accept(ASTPrinter *printer) override;
    };

}


#endif //SIMPLE_C_COMPILER_INCREMENTDECREMENTEXPRESSION_H

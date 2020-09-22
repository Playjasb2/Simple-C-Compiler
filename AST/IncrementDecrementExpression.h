//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_INCREMENTDECREMENTEXPRESSION_H
#define SIMPLE_C_COMPILER_INCREMENTDECREMENTEXPRESSION_H


#include "UnaryExpression.h"
#include "VariableStatement.h"

enum IncrementDecrementOperator {
    plus_plus_prefix = 1,
    plus_plus_postfix,
    minus_minus_prefix,
    minus_minus_postfix
};

class IncrementDecrementExpression: public UnaryExpression<string>, public VariableStatement {

private:
    IncrementDecrementOperator op;
    bool isStatement;

public:
    IncrementDecrementExpression(string variable_name, IncrementDecrementOperator op, bool isStatement);
    void accept(ASTPrinter *printer) override;
};


#endif //SIMPLE_C_COMPILER_INCREMENTDECREMENTEXPRESSION_H

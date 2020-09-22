//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_CONDITIONALEXPRESSION_H
#define SIMPLE_C_COMPILER_CONDITIONALEXPRESSION_H

#include "BinaryExpression.h"

enum Conditional_operators {
    equal_equal = 1,
    not_equal,
    less_than,
    less_than_or_equal_to,
    greater_than,
    greater_than_or_equal_to,
    and_,
    or_,
    CONDITIONAL_OPERATORS_MAX
};

const char *conditional_operator_symbols[Conditional_operators::CONDITIONAL_OPERATORS_MAX] =
        {"==", "!=", "<", "<=", ">", ">=", "&&", "||"};

class ConditionalExpression: public BinaryExpression {

public:
    ConditionalExpression(Conditional_operators op, Expression LHS, Expression RHS);
    void accept(ASTPrinter *printer) override;
};


#endif //SIMPLE_C_COMPILER_CONDITIONALEXPRESSION_H

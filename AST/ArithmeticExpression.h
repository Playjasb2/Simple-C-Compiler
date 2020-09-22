//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_ARITHMETICEXPRESSION_H
#define SIMPLE_C_COMPILER_ARITHMETICEXPRESSION_H


#include "BinaryExpression.h"

enum Operator {
    add = 1,
    subtract,
    multiply,
    divide,
    modulo,
    OPERATION_MAX
};

const char *operator_symbols[OPERATION_MAX] = {"+", "-", "*", "/", "%"};

class ArithmeticExpression: public BinaryExpression {

public:
    ArithmeticExpression(Operator operation_symbol, const Expression& LHS, const Expression& RHS);
    void accept(ASTPrinter *printer) override;
};


#endif //SIMPLE_C_COMPILER_ARITHMETICEXPRESSION_H

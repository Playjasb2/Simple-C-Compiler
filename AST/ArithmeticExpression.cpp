//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "ArithmeticExpression.h"

ArithmeticExpression::ArithmeticExpression(Operator op, const Expression& LHS, const Expression& RHS):
BinaryExpression(operator_symbols[op], LHS, RHS){

}

void ArithmeticExpression::accept(ASTPrinter *printer) {
    printer->visit(this);
}
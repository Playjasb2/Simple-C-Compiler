//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "ArithmeticExpression.h"
#include "ASTPrinter.h"

using namespace AST;

ArithmeticExpression::ArithmeticExpression(Operator op, const Expression& LHS, const Expression& RHS):
BinaryExpression(operator_symbols[op], LHS, RHS){

}

void ArithmeticExpression::accept(ASTPrinter *printer) {
    printer->visit(this);
}
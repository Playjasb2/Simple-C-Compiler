//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "ArithmeticExpression.h"
#include "ASTPrinter.h"

using namespace AST;

ArithmeticExpression::ArithmeticExpression(Operator op, Expression *LHS, Expression *RHS, Token *operator_token):
op(op), BinaryExpression(operator_token, LHS, RHS) {

}


void ArithmeticExpression::accept(ASTPrinter *printer) {
    printer->visit(this);
}

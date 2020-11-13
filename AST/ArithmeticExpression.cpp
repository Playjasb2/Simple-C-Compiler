//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "ArithmeticExpression.h"

using namespace AST;

ArithmeticExpression::ArithmeticExpression(Operator op, Expression *LHS, Expression *RHS, Token *operator_token):
op(op), BinaryExpression(operator_token, LHS, RHS) {

}


void ArithmeticExpression::accept(Visitor *visitor) {
    visitor->visit(this);
}

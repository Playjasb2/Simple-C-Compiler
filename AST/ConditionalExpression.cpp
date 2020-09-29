//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "ConditionalExpression.h"

using namespace AST;

ConditionalExpression::ConditionalExpression(Conditional_Operators op, Expression *LHS, Expression *RHS,
                                             Token *operator_token): op(op),
                                             BinaryExpression(operator_token, LHS, RHS) {

}

void ConditionalExpression::accept(ASTPrinter *printer) {
    printer->visit(this);
}

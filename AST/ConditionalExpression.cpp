//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "ConditionalExpression.h"

ConditionalExpression::ConditionalExpression(Conditional_operators op, Expression LHS, Expression RHS):
BinaryExpression(conditional_operator_symbols[op], LHS, RHS){

}

void ConditionalExpression::accept(ASTPrinter *printer) {
    printer->visit(this);
}

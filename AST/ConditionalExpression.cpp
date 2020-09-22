//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "ConditionalExpression.h"

#include <utility>
#include "ASTPrinter.h"

using namespace AST;

ConditionalExpression::ConditionalExpression(Conditional_operators op, Expression LHS, Expression RHS):
BinaryExpression(conditional_operator_symbols[op], std::move(LHS), std::move(RHS)){

}

void ConditionalExpression::accept(ASTPrinter *printer) {
    printer->visit(this);
}

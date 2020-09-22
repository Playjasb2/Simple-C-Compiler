//
// Created by Jasmeet Brar on 2020-09-16.
//

#include <utility>
#include "BinaryExpression.h"

using namespace AST;

BinaryExpression::BinaryExpression(string operation_symbol, Expression LHS, Expression RHS):
operation_symbol(std::move(operation_symbol)), LHS(std::move(LHS)), RHS(std::move(RHS)){

}

Expression BinaryExpression::getLeft() {
    return this->LHS;
}

Expression BinaryExpression::getRight() {
    return this->RHS;
}

string BinaryExpression::getOperationSymbol() {
    return this->operation_symbol;
}



//
// Created by Jasmeet Brar on 2020-09-16.
//

#include <utility>
#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(string operation_symbol, Expression LHS, Expression RHS):
operation_symbol(std::move(operation_symbol)), LHS(LHS), RHS(RHS){

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



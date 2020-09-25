//
// Created by Jasmeet Brar on 2020-09-16.
//

#include <utility>
#include "BinaryExpression.h"

using namespace AST;

BinaryExpression::BinaryExpression(Token *operator_token, Expression *LHS, Expression *RHS): LHS(LHS), RHS(RHS),
operator_token(operator_token) {

}

Expression *BinaryExpression::getLHS() {
    return this->LHS;
}

Expression *BinaryExpression::getRHS() {
    return this->RHS;
}

BinaryExpression::~BinaryExpression() {
    delete this->LHS;
    delete this->RHS;
}



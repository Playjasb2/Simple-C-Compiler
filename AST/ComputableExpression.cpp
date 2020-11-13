//
// Created by Jasmeet Brar on 2020-10-20.
//

#include "ComputableExpression.h"

using namespace AST;

ComputableExpression::ComputableExpression(Token *operator_token, Expression *LHS, Expression *RHS) : BinaryExpression(
        operator_token, LHS, RHS){

}

ComputableExpression::ComputableExpression(Token *operator_token, Expression *LHS, Expression *RHS,
                                           StatementList *before, StatementList *after): BinaryExpression(
        operator_token, LHS, RHS), before(before), after(after){

}

void ComputableExpression::accept(Visitor *visitor) {
    visitor->visit(this);
}

int ComputableExpression::getOperatorPrecedence(Token_Type type) {
    auto element = std::find(std::begin(ComputableExpression::computable_operators),
                           std::end(ComputableExpression::computable_operators), type);
    if(element != std::end(ComputableExpression::computable_operators)) {
        auto index = std::distance(std::begin(ComputableExpression::computable_operators), element);
        return ComputableExpression::computable_operators_precedence[index];
    }

    return -1;
}

StatementList *ComputableExpression::getBeforeStatements() {
    return this->before;
}

StatementList *ComputableExpression::getAfterStatements() {
    return this->after;
}

void ComputableExpression::emptyBeforeAndAfter() {
    this->before = nullptr;
    this->after = nullptr;
}

void ComputableExpression::setBefore(StatementList *beforeStatements) {
    this->before = beforeStatements;
}

void ComputableExpression::setAfter(StatementList *afterStatements) {
    this->after = afterStatements;
}

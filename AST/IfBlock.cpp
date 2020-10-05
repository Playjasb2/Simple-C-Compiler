//
// Created by Jasmeet Brar on 2020-10-04.
//

#include "IfBlock.h"

using namespace AST;

IfBlock::IfBlock(ConditionalExpression *conditionalExpression, StatementList *statementList):
conditionalExpression(conditionalExpression), statementList(statementList) {

}

IfBlock::IfBlock(StatementList *statementList): conditionalExpression(nullptr), statementList(statementList) {

}

ConditionalExpression *IfBlock::getConditionalExpression() {
    return this->conditionalExpression;
}

StatementList *IfBlock::getStatementList() {
    return this->statementList;
}

IfBlock::~IfBlock() {
    delete this->conditionalExpression;
    delete this->statementList;
}

void IfBlock::accept(ASTPrinter *printer) {
    printer->visit(this);
}

//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "IfStatement.h"

using namespace AST;

IfStatement::IfStatement(ConditionalExpression *conditional_expression, StatementList *if_block,
                         StatementList *else_block): conditional_expression(conditional_expression),
                         if_block(if_block), else_block(else_block) {

}

void IfStatement::accept(ASTPrinter *printer) {
    printer->visit(this);
}

IfStatement::~IfStatement() {
    delete this->conditional_expression;
    delete this->if_block;
    delete this->else_block;
}

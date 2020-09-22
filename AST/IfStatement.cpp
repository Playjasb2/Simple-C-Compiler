//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "IfStatement.h"

#include <utility>

IfStatement::IfStatement(ConditionalExpression conditional_expression, StatementList if_block, StatementList else_block)
: conditional_expression(std::move(conditional_expression)), if_block(if_block), else_block(else_block){

}

void IfStatement::accept(ASTPrinter *printer) {
    printer->visit(this);
}

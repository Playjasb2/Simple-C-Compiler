//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "IfStatement.h"
#include "ASTPrinter.h"

#include <utility>

using namespace AST;

IfStatement::IfStatement(ConditionalExpression conditional_expression, StatementList if_block, StatementList else_block)
: conditional_expression(std::move(conditional_expression)), if_block(std::move(if_block)),
else_block(std::move(else_block)){

}

void IfStatement::accept(ASTPrinter *printer) {
    printer->visit(this);
}

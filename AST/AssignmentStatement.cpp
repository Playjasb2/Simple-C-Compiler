//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "AssignmentStatement.h"
#include "ASTPrinter.h"

#include <utility>

using namespace AST;

AssignmentStatement::AssignmentStatement(string variable_name, Assignment_Operator op, Expression expression):
op(op), expression(std::move(expression)), VariableStatement(std::move(variable_name)){

}

Expression AssignmentStatement::getExpression() {
    return this->expression;
}

Assignment_Operator AssignmentStatement::getAssignmentOperator() {
    return this->op;
}

void AssignmentStatement::accept(ASTPrinter *printer) {
    printer->visit(this);
}

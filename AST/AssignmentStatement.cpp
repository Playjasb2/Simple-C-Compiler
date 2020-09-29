//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "AssignmentStatement.h"

using namespace AST;

AssignmentStatement::AssignmentStatement(Variable *variable, Assignment_Operator op, Expression *expression,
                                         Token *operator_token): expression(expression), op(op),
                                         operator_token(operator_token), VariableStatement(variable) {

}

Expression *AssignmentStatement::getExpression() {
    return this->expression;
}

Assignment_Operator AssignmentStatement::getAssignmentOperator() {
    return this->op;
}

void AssignmentStatement::accept(ASTPrinter *printer) {
    printer->visit(this);
}

AssignmentStatement::~AssignmentStatement() {
    delete this->expression;
}



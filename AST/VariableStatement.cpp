//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "VariableStatement.h"

using namespace AST;

VariableStatement::VariableStatement(Variable *variable): variable(variable){

}

Variable *VariableStatement::getVariable() {
    return this->variable;
}

VariableStatement::~VariableStatement() {
    delete this->variable;
}

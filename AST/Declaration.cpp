//
// Created by Jasmeet Brar on 2020-09-18.
//

#include "Declaration.h"
#include <utility>

using namespace AST;

Declaration::Declaration(Variable *variable) : VariableStatement(variable) {

}

Declaration::Declaration(Variable *variable, Expression *value): value(value), VariableStatement(variable) {

}

Expression *Declaration::getVariableValue() {
    return this->value;
}

Declaration::~Declaration() {
    delete this->value;
}

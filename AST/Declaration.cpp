//
// Created by Jasmeet Brar on 2020-09-18.
//

#include "Declaration.h"

using namespace AST;

Declaration::Declaration(Variable *variable) : VariableStatement(variable), value(nullptr) {

}

Declaration::Declaration(Variable *variable, Expression *value): value(value), VariableStatement(variable) {

}

Expression *Declaration::getVariableValue() {
    return this->value;
}

Declaration::~Declaration() {
    delete this->value;
}

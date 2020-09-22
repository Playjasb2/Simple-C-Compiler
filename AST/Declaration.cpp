//
// Created by Jasmeet Brar on 2020-09-18.
//

#include "Declaration.h"
#include <utility>

using namespace AST;

Declaration::Declaration(Type variable_type, const string& variable_name, Expression value):
variable_type(variable_type), variable_name(variable_name), value(std::move(value)), VariableStatement(variable_name){

}

string Declaration::getVariableType() {
    return Type_Names[this->variable_type];
}

Expression Declaration::getVariableValue() {
    return this->value;
}


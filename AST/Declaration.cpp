//
// Created by Jasmeet Brar on 2020-09-18.
//

#include "Declaration.h"
#include <utility>

using namespace AST;

Declaration::Declaration(Type variable_type, string variable_name, Expression value):
variable_type(variable_type), value(std::move(value)), VariableStatement(std::move(variable_name)){

}

Declaration::Declaration(Type variable_type, string variable_name):
variable_type(variable_type), VariableStatement(std::move(variable_name)){

}


string Declaration::getVariableType() {
    return Type_Names[this->variable_type];
}

Expression Declaration::getVariableValue() {
    return this->value;
}



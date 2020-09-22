//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "VariableStatement.h"

#include <utility>

using namespace AST;

VariableStatement::VariableStatement(string variable_name): variable_name(std::move(variable_name)){

}

string VariableStatement::getVariableName() {
    return this->variable_name;
}

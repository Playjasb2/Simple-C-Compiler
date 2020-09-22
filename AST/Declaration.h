//
// Created by Jasmeet Brar on 2020-09-18.
//

#ifndef SIMPLE_C_COMPILER_DECLARATION_H
#define SIMPLE_C_COMPILER_DECLARATION_H

#include <string>
#include "Types.h"
#include "Expression.h"
#include "VariableStatement.h"

using namespace std;

class Declaration: public VariableStatement {

private:
    Type variable_type;
    string variable_name;
    Expression value;

protected:
    Declaration(Type variable_type, const string& variable_name, Expression value);

public:
    string getVariableType();
    Expression getVariableValue();
};

#endif //SIMPLE_C_COMPILER_DECLARATION_H

//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_VARIABLESTATEMENT_H
#define SIMPLE_C_COMPILER_VARIABLESTATEMENT_H

#include <string>
#include "Statement.h"

using namespace std;

namespace AST {

    class VariableStatement : public Statement {

    private:
        string variable_name;

    protected:
        explicit VariableStatement(string variable_name);

    public:
        string getVariableName();
    };

}

#endif //SIMPLE_C_COMPILER_VARIABLESTATEMENT_H

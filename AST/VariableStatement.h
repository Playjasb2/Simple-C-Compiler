//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_VARIABLESTATEMENT_H
#define SIMPLE_C_COMPILER_VARIABLESTATEMENT_H

#include <string>
#include "Statement.h"
#include "Variable.h"

using namespace std;

namespace AST {

    class VariableStatement : public Statement {

    private:
        Variable *variable;

    protected:
        explicit VariableStatement(Variable *variable);
        ~VariableStatement() override;

    public:
        Variable *getVariable();

    };

}

#endif //SIMPLE_C_COMPILER_VARIABLESTATEMENT_H

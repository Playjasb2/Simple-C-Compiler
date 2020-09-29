//
// Created by Jasmeet Brar on 2020-09-18.
//

#ifndef SIMPLE_C_COMPILER_DECLARATION_H
#define SIMPLE_C_COMPILER_DECLARATION_H

#include <string>
#include "Types.h"
#include "Expression.h"
#include "Variable.h"
#include "VariableStatement.h"

namespace AST {

    class Declaration : public VariableStatement {

    private:
        Expression *value;

    protected:
        explicit Declaration(Variable *variable);
        ~Declaration() override;
        Declaration(Variable *variable, Expression *value);

    public:
        Expression *getVariableValue();
    };

}

#endif //SIMPLE_C_COMPILER_DECLARATION_H

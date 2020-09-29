//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_ASSIGNMENTSTATEMENT_H
#define SIMPLE_C_COMPILER_ASSIGNMENTSTATEMENT_H

#include "VariableStatement.h"
#include "Expression.h"

namespace AST {
    enum Assignment_Operator {
        equal = 1,
        plus_equal,
        minus_equal,
        multiply_equal,
        divide_equal
    };

    class AssignmentStatement: public VariableStatement {

    private:
        Expression *expression;
        Assignment_Operator op;
        Token *operator_token;

    public:
        AssignmentStatement(Variable *variable, Assignment_Operator op, Expression *expression, Token *operator_token);
        ~AssignmentStatement() override;
        Expression *getExpression();
        Assignment_Operator getAssignmentOperator();
        void accept(ASTPrinter *printer) override;
    };
}


#endif //SIMPLE_C_COMPILER_ASSIGNMENTSTATEMENT_H

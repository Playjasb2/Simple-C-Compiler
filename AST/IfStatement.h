//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_IFSTATEMENT_H
#define SIMPLE_C_COMPILER_IFSTATEMENT_H


#include "VariableStatement.h"
#include "StatementList.h"
#include "ConditionalExpression.h"


namespace AST {

    class IfStatement : public Statement {

    private:
        ConditionalExpression *conditional_expression;
        StatementList *if_block;
        StatementList *else_block;

    public:
        IfStatement(ConditionalExpression *conditional_expression, StatementList *if_block, StatementList *else_block);
        ~IfStatement() override;
        void accept(ASTPrinter *printer) override;
    };

}

#endif //SIMPLE_C_COMPILER_IFSTATEMENT_H

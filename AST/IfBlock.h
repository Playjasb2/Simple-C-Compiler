//
// Created by Jasmeet Brar on 2020-10-04.
//

#ifndef SIMPLE_C_COMPILER_IFBLOCK_H
#define SIMPLE_C_COMPILER_IFBLOCK_H

#include "ConditionalExpression.h"
#include "StatementList.h"
#include "ASTNode.h"

using namespace AST;

namespace AST {

    class IfBlock : public ASTNode {
    private:
        ConditionalExpression *conditionalExpression;
        StatementList *statementList;

    public:
        IfBlock(ConditionalExpression *conditionalExpression, StatementList *statementList);
        explicit IfBlock(StatementList *statementList);
        ~IfBlock() override;
        ConditionalExpression *getConditionalExpression();
        StatementList *getStatementList();
        void accept(ASTPrinter *printer) override;
    };

}


#endif //SIMPLE_C_COMPILER_IFBLOCK_H

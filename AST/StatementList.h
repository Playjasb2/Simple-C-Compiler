//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_STATEMENTLIST_H
#define SIMPLE_C_COMPILER_STATEMENTLIST_H

#include <vector>
#include "Statement.h"
#include "ASTNode.h"

namespace AST {

    class StatementList : public ASTNode {

    private:
        std::vector<Statement *> *statements = new std::vector<Statement *>();

    public:
        explicit StatementList();
        explicit StatementList(Statement *statement);
        ~StatementList() override;
        void addStatement(Statement *statement);
        unsigned int getNumOfStatements();
        std::vector<Statement *> *getStatements();
        void accept(ASTPrinter *printer) override;
    };

}

#endif //SIMPLE_C_COMPILER_STATEMENTLIST_H

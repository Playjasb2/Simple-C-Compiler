//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_STATEMENTLIST_H
#define SIMPLE_C_COMPILER_STATEMENTLIST_H

#include <vector>
#include "Statement.h"
#include "ASTNode.h"
#include "ASTPrinter.h"

using namespace std;

namespace AST {

    class StatementList : public ASTNode {

    private:
        vector<Statement *> *statements = new vector<Statement *>();

    public:
        explicit StatementList();
        explicit StatementList(Statement *statement);
        ~StatementList() override;
        void addStatement(Statement *statement);
        unsigned int getNumOfStatements();
        vector<Statement *> *getStatements();
        void accept(ASTPrinter *printer) override;
    };

}

#endif //SIMPLE_C_COMPILER_STATEMENTLIST_H

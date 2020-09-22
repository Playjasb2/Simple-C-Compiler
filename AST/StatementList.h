//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_STATEMENTLIST_H
#define SIMPLE_C_COMPILER_STATEMENTLIST_H

#include <vector>
#include "Statement.h"

using namespace std;

class StatementList: public ASTNode {

private:
    vector<Statement> statements = vector<Statement>();

public:
    explicit StatementList();
    void addStatement(const Statement& statement);
    unsigned int getNumOfStatements();
    void accept(ASTPrinter *printer) override;
};

#endif //SIMPLE_C_COMPILER_STATEMENTLIST_H

//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "StatementList.h"
#include "ASTPrinter.h"

using namespace AST;

StatementList::StatementList()= default;


void StatementList::addStatement(const Statement& statement) {
    this->statements.push_back(statement);
}

unsigned int StatementList::getNumOfStatements() {
    return this->statements.size();
}

void StatementList::accept(ASTPrinter *printer) {
    printer->visit(this);
}

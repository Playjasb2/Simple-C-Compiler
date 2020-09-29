//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "StatementList.h"

using namespace AST;

StatementList::StatementList()= default;

StatementList::StatementList(Statement *statement) {
    this->statements->push_back(statement);
}


void StatementList::addStatement(Statement *statement) {
    this->statements->push_back(statement);
}

unsigned int StatementList::getNumOfStatements() {
    return this->statements->size();
}

void StatementList::accept(ASTPrinter *printer) {
    printer->visit(this);
}

std::vector<Statement *> *StatementList::getStatements() {
    return this->statements;
}

StatementList::~StatementList() {
    for(auto &statement: *this->statements) {
        delete statement;
    }

    delete this->statements;

}



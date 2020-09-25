//
// Created by Jasmeet Brar on 2020-09-22.
//

#include "Program.h"

#include <utility>

using namespace AST;

Program::Program() = default;

Program::Program(StatementList *statementList): statementList(statementList){

}

Program::Program(StatementList *statementList, vector<string> *errors):
statementList(statementList), errors(errors){

}

void Program::accept(ASTPrinter *printer) {
    printer->visit(this);
}

Program::~Program() {
    delete this->statementList;
    delete this->errors;
}




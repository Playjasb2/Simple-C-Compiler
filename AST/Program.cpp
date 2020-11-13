//
// Created by Jasmeet Brar on 2020-09-22.
//

#include "Program.h"

using namespace AST;

Program::Program() = default;

Program::Program(StatementList *statementList): statementList(statementList){

}

Program::Program(StatementList *statementList, std::vector<std::string> *errors):
statementList(statementList), errors(errors){

}

void Program::accept(Visitor *visitor) {
    visitor->visit(this);
}

Program::~Program() {
    delete this->statementList;
    delete this->errors;
}




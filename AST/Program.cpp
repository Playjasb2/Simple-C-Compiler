//
// Created by Jasmeet Brar on 2020-09-22.
//

#include "Program.h"

#include <utility>

using namespace AST;

Program::Program() = default;

Program::Program(StatementList statementList): statementList(std::move(statementList)){

}

Program::Program(StatementList statementList, vector<string> errors):
statementList(std::move(statementList)), errors(std::move(errors)){

}

void Program::accept(ASTPrinter *printer) {
    printer->visit(this);
}



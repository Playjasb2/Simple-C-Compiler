//
// Created by Jasmeet Brar on 2020-09-22.
//

#include "Program.h"

#include <utility>

using namespace AST;

Program::Program() = default;

Program::Program(StatementList statementList): statementList(std::move(statementList)){

}
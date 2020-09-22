//
// Created by Jasmeet Brar on 2020-09-22.
//

#include "Program.h"

#include <utility>

Program::Program() = default;

Program::Program(StatementList statementList): statementList(std::move(statementList)){

}
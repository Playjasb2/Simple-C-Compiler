//
// Created by Jasmeet Brar on 2020-09-21.
//

#include "FunctionCall.h"
#include "ASTPrinter.h"

#include <utility>

using namespace AST;

FunctionCall::FunctionCall(string function_name, bool isStatement): function_name(std::move(function_name)),
isStatement(isStatement){

}

FunctionCall::FunctionCall(string function_name, vector<Expression> arguments, bool isStatement):
function_name(std::move(function_name)), arguments(std::move(arguments)), isStatement(isStatement){

}

vector<Expression> FunctionCall::getArguments() {
    return this->arguments;
}

void FunctionCall::accept(ASTPrinter *printer) {
    printer->visit(this);
}

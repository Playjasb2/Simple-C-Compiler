//
// Created by Jasmeet Brar on 2020-09-21.
//

#include "FunctionCall.h"
#include "ASTPrinter.h"

#include <utility>

using namespace AST;

FunctionCall::FunctionCall(Function *function, bool isStatement): function(function), isStatement(isStatement){

}

FunctionCall::FunctionCall(Function *function, vector<Expression *> *arguments, vector<Token *> *argument_tokens,
                           bool isStatement): function(function), arguments(arguments),
                           argument_tokens(argument_tokens), isStatement(isStatement) {

}

vector<Expression *> *FunctionCall::getArguments() {
    return this->arguments;
}

void FunctionCall::accept(ASTPrinter *printer) {
    printer->visit(this);
}

FunctionCall::~FunctionCall() {
    delete this->function;
    delete this->arguments;
    delete this->argument_tokens;
}

//
// Created by Jasmeet Brar on 2020-09-21.
//

#include "FunctionCall.h"

#include <utility>

FunctionCall::FunctionCall(string function_name): function_name(std::move(function_name)){

}

FunctionCall::FunctionCall(string function_name, vector<Expression> arguments):
function_name(std::move(function_name)), arguments(std::move(arguments)){

}

vector<Expression> FunctionCall::getArguments() {
    return this->arguments;
}

void FunctionCall::accept(ASTPrinter *printer) {
    printer->visit(this);
}

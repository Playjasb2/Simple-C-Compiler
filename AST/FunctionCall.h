//
// Created by Jasmeet Brar on 2020-09-21.
//

#ifndef SIMPLE_C_COMPILER_FUNCTIONCALL_H
#define SIMPLE_C_COMPILER_FUNCTIONCALL_H

#include <string>
#include <vector>
#include "Expression.h"

using namespace std;

class FunctionCall: public Expression {

private:
    string function_name;
    vector<Expression> arguments = vector<Expression>();

public:
    explicit FunctionCall(string function_name);
    FunctionCall(string function_name, vector<Expression> arguments);
    vector<Expression> getArguments();
    void accept(ASTPrinter *printer) override;
};


#endif //SIMPLE_C_COMPILER_FUNCTIONCALL_H

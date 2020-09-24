//
// Created by Jasmeet Brar on 2020-09-21.
//

#ifndef SIMPLE_C_COMPILER_FUNCTIONCALL_H
#define SIMPLE_C_COMPILER_FUNCTIONCALL_H

#include <string>
#include <vector>
#include "Expression.h"
#include "Statement.h"
#include "ASTPrinter.h"

using namespace std;

namespace AST {

    class FunctionCall : public Expression, public Statement {

    private:
        string function_name;
        bool isStatement;
        vector<Expression> arguments = vector<Expression>();

    public:
        explicit FunctionCall(string function_name, bool isStatement);
        FunctionCall(string function_name, vector<Expression> arguments, bool isStatement);
        vector<Expression> getArguments();
        void accept(ASTPrinter *printer) override;
    };

}


#endif //SIMPLE_C_COMPILER_FUNCTIONCALL_H

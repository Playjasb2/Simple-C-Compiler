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
#include "Function.h"

using namespace std;

namespace AST {

    class FunctionCall : public Expression, public Statement {

    private:
        Function *function;
        bool isStatement;
        vector<Expression *> *arguments = new vector<Expression *>();
        vector<Token *> *argument_tokens = new vector<Token *>();

    public:
        explicit FunctionCall(Function *function, bool isStatement);
        ~FunctionCall() override;
        FunctionCall(Function *function, vector<Expression *> *arguments, vector<Token *> *argument_tokens,
                     bool isStatement);
        vector<Expression *> *getArguments();
        void accept(ASTPrinter *printer) override;
    };

}


#endif //SIMPLE_C_COMPILER_FUNCTIONCALL_H

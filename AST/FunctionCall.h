//
// Created by Jasmeet Brar on 2020-09-21.
//

#ifndef SIMPLE_C_COMPILER_FUNCTIONCALL_H
#define SIMPLE_C_COMPILER_FUNCTIONCALL_H

#include <string>
#include <vector>
#include "Expression.h"
#include "Statement.h"
#include "Function.h"

namespace AST {

    class FunctionCall : public Expression, public Statement {

    private:
        Function *function;
        bool isStatement;
        std::vector<Expression *> *arguments = new std::vector<Expression *>();

    public:
        explicit FunctionCall(Function *function, bool isStatement);
        ~FunctionCall() override;
        FunctionCall(Function *function, std::vector<Expression *> *arguments, bool isStatement);
        std::vector<Expression *> *getArguments();
        void accept(Visitor *visitor) override;
    };

}


#endif //SIMPLE_C_COMPILER_FUNCTIONCALL_H

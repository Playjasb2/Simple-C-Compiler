//
// Created by Jasmeet Brar on 2020-09-18.
//

#ifndef SIMPLE_C_COMPILER_UNARYEXPRESSION_H
#define SIMPLE_C_COMPILER_UNARYEXPRESSION_H

#include <string>
#include <utility>
#include "Expression.h"
#include "ASTPrinter.h"

using namespace std;

namespace AST {

    class UnaryExpression : public Expression {

    private:
        Expression *expression;

    protected:
        explicit UnaryExpression(Expression *subject);
        ~UnaryExpression() override;

    public:
        Expression *getExpression();

        void accept(ASTPrinter *printer) override;
    };

}

#endif //SIMPLE_C_COMPILER_UNARYEXPRESSION_H

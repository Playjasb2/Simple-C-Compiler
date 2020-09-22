//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_NOTEXPRESSION_H
#define SIMPLE_C_COMPILER_NOTEXPRESSION_H


#include "UnaryExpression.h"
#include "ASTPrinter.h"

namespace AST {

    class NotExpression : public UnaryExpression<Expression> {

    private:
        Expression expression;

    public:
        explicit NotExpression(Expression expression);
        void accept(ASTPrinter *printer) override;
    };

}


#endif //SIMPLE_C_COMPILER_NOTEXPRESSION_H

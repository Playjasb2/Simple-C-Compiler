//
// Created by Jasmeet Brar on 2020-09-18.
//

#ifndef SIMPLE_C_COMPILER_UNARYEXPRESSION_H
#define SIMPLE_C_COMPILER_UNARYEXPRESSION_H

#include <string>
#include "Expression.h"

namespace AST {

    class UnaryExpression : public Expression {

    private:
        Expression *expression;

    protected:
        explicit UnaryExpression(Expression *subject);
        ~UnaryExpression() override;

    public:
        Expression *getExpression();

        void accept(Visitor *visitor) override;
    };

}

#endif //SIMPLE_C_COMPILER_UNARYEXPRESSION_H

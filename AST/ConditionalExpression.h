//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_CONDITIONALEXPRESSION_H
#define SIMPLE_C_COMPILER_CONDITIONALEXPRESSION_H

#include "BinaryExpression.h"

namespace AST {

    enum Conditional_Operators {
        equal_equal = 1,
        not_equal,
        less_than,
        less_than_or_equal_to,
        greater_than,
        greater_than_or_equal_to,
        and_,
        or_
    };

    class ConditionalExpression : public BinaryExpression {

    private:
        Conditional_Operators op;

    public:
        ConditionalExpression(Conditional_Operators op, Expression *LHS, Expression *RHS, Token *operator_token);
        void accept(ASTPrinter *printer) override;
    };

}


#endif //SIMPLE_C_COMPILER_CONDITIONALEXPRESSION_H

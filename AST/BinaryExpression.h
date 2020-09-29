//
// Created by Jasmeet Brar on 2020-09-18.
//

#ifndef SIMPLE_C_COMPILER_BINARYEXPRESSION_H
#define SIMPLE_C_COMPILER_BINARYEXPRESSION_H

#include <string>
#include "Expression.h"

namespace AST {

    class BinaryExpression : public Expression {

    private:
        Expression *LHS;
        Expression *RHS;
        Token *operator_token;

    protected:
        BinaryExpression(Token *operator_token, Expression *LHS, Expression *RHS);
        ~BinaryExpression() override;

    public:
        Expression *getLHS();
        Expression *getRHS();
    };

}

#endif //SIMPLE_C_COMPILER_BINARYEXPRESSION_H

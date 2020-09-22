//
// Created by Jasmeet Brar on 2020-09-18.
//

#ifndef SIMPLE_C_COMPILER_BINARYEXPRESSION_H
#define SIMPLE_C_COMPILER_BINARYEXPRESSION_H

#include <string>
#include "Expression.h"

using namespace std;

class BinaryExpression: public Expression {

private:
    Expression LHS;
    Expression RHS;
    string operation_symbol;

protected:
    BinaryExpression(string operation_symbol, Expression LHS, Expression RHS);

public:
    Expression getLeft();
    Expression getRight();
    string getOperationSymbol();
};

#endif //SIMPLE_C_COMPILER_BINARYEXPRESSION_H

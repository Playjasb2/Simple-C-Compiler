//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "IncrementDecrementExpression.h"

using namespace AST;

IncrementDecrementExpression::IncrementDecrementExpression(Variable *variable, IncrementDecrementOperator op,
                                                           bool isStatement): op(op), isStatement(isStatement),
                                                           UnaryExpression(variable), VariableStatement(variable) {


}


void IncrementDecrementExpression::accept(Visitor *visitor) {
    visitor->visit(this);
}


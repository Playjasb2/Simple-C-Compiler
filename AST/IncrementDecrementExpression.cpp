//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "IncrementDecrementExpression.h"
#include "ASTPrinter.h"

#include <utility>

using namespace AST;

IncrementDecrementExpression::IncrementDecrementExpression(string variable_name, IncrementDecrementOperator op,
                                                           bool isStatement): op(op), isStatement(isStatement),
                                                           UnaryExpression<string>(std::move(variable_name)),
                                                                   VariableStatement(variable_name){

}

void IncrementDecrementExpression::accept(ASTPrinter *printer) {
    printer->visit(this);
}

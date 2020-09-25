//
// Created by Jasmeet Brar on 2020-09-24.
//

#include "UnaryExpression.h"

#include <utility>

UnaryExpression::UnaryExpression(Expression *expression): expression(expression){

}

Expression *UnaryExpression::getExpression() {
    return this->expression;
}

void UnaryExpression::accept(ASTPrinter *printer){
    printer->visit(this);
}

UnaryExpression::~UnaryExpression() {
    delete this->expression;
}



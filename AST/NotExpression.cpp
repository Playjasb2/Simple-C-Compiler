//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "NotExpression.h"

NotExpression::NotExpression(Expression expression): UnaryExpression(expression){

}

void NotExpression::accept(ASTPrinter *printer) {
    printer->visit(this);
}

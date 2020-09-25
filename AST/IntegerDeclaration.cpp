//
// Created by Jasmeet Brar on 2020-09-18.
//

#include "IntegerDeclaration.h"

#include <utility>
#include "ASTPrinter.h"

using namespace AST;

IntegerDeclaration::IntegerDeclaration(Variable *variable): Declaration(variable){

}

IntegerDeclaration::IntegerDeclaration(Variable *variable, Expression *value): Declaration(variable, value) {

}

void IntegerDeclaration::accept(ASTPrinter *printer) {
    printer->visit(this);
}



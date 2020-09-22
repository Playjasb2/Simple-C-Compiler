//
// Created by Jasmeet Brar on 2020-09-18.
//

#include "IntegerDeclaration.h"

IntegerDeclaration::IntegerDeclaration(const string& variable_name, Expression value):
Declaration(Type::Integer, variable_name, value) {

}

void IntegerDeclaration::accept(ASTPrinter *printer) {
    printer->visit(this);
}

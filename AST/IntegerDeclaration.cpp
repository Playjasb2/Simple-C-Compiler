//
// Created by Jasmeet Brar on 2020-09-18.
//

#include "IntegerDeclaration.h"

#include <utility>
#include "ASTPrinter.h"

using namespace AST;

IntegerDeclaration::IntegerDeclaration(const string& variable_name, Expression value):
Declaration(Type::Integer, variable_name, std::move(value)) {

}

void IntegerDeclaration::accept(ASTPrinter *printer) {
    printer->visit(this);
}

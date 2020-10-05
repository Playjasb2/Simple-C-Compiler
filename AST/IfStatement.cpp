//
// Created by Jasmeet Brar on 2020-09-19.
//

#include "IfStatement.h"

using namespace AST;

IfStatement::IfStatement(std::vector<IfBlock *> *ifBlocks): ifBlocks(ifBlocks){

}

void IfStatement::accept(ASTPrinter *printer) {
    printer->visit(this);
}

IfStatement::~IfStatement() {
    delete this->ifBlocks;
}

std::vector<IfBlock *> *IfStatement::getIfBlocks() {
    return this->ifBlocks;
}



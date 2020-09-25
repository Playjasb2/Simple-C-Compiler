//
// Created by Jasmeet Brar on 2020-09-21.
//

#ifndef SIMPLE_C_COMPILER_ASTNODE_H
#define SIMPLE_C_COMPILER_ASTNODE_H

#include <token.h>
#include <string>
#include "ASTPrinter.h"

using namespace std;

namespace AST {

    class ASTNode {

    public:
        virtual void accept(ASTPrinter *printer) {

        }
        virtual ~ASTNode()= default;
    };
}

#endif //SIMPLE_C_COMPILER_ASTNODE_H

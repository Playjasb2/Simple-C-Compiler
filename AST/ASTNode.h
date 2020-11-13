//
// Created by Jasmeet Brar on 2020-09-21.
//

#ifndef SIMPLE_C_COMPILER_ASTNODE_H
#define SIMPLE_C_COMPILER_ASTNODE_H

#include <token.h>
#include <string>
#include "../lib/Visitor.h"

namespace AST {

    class ASTNode {

    public:
        virtual void accept(Visitor *visitor) {

        }
        virtual ~ASTNode()= default;
    };
}

#endif //SIMPLE_C_COMPILER_ASTNODE_H

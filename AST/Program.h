//
// Created by Jasmeet Brar on 2020-09-22.
//

#ifndef SIMPLE_C_COMPILER_PROGRAM_H
#define SIMPLE_C_COMPILER_PROGRAM_H

#include "ASTNode.h"
#include "StatementList.h"

namespace AST {

    class Program : public ASTNode {

    private:
        StatementList statementList = StatementList();

    public:
        Program();
        explicit Program(StatementList statementList);
    };

}

#endif //SIMPLE_C_COMPILER_PROGRAM_H

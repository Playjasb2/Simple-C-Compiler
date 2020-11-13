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
        StatementList *statementList = new StatementList();
        std::vector<std::string> *errors  = new std::vector<std::string>();

    public:
        Program();
        ~Program() override;
        explicit Program(StatementList *statementList);
        explicit Program(StatementList *statementList, std::vector<std::string> *errors);
        void accept(Visitor *visitor) override;
    };

}

#endif //SIMPLE_C_COMPILER_PROGRAM_H

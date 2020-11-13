//
// Created by Jasmeet Brar on 2020-09-19.
//

#ifndef SIMPLE_C_COMPILER_IFSTATEMENT_H
#define SIMPLE_C_COMPILER_IFSTATEMENT_H

#include "Statement.h"
#include "IfBlock.h"


namespace AST {

    class IfStatement : public Statement {

    private:
        std::vector<IfBlock *> *ifBlocks;

    public:
        explicit IfStatement(std::vector<IfBlock *> *ifBlocks);
        ~IfStatement() override;
        std::vector<IfBlock *> *getIfBlocks();
        void accept(Visitor *visitor) override;
    };

}

#endif //SIMPLE_C_COMPILER_IFSTATEMENT_H

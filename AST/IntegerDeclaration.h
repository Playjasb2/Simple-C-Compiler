//
// Created by Jasmeet Brar on 2020-09-18.
//

#ifndef SIMPLE_C_COMPILER_INTEGERDECLARATION_H
#define SIMPLE_C_COMPILER_INTEGERDECLARATION_H

#include "Declaration.h"
#include "ASTPrinter.h"

namespace AST {

    class IntegerDeclaration : public Declaration {

    public:
        IntegerDeclaration(const string &variable_name, Expression value);
        void accept(ASTPrinter *printer) override;
    };

}


#endif //SIMPLE_C_COMPILER_INTEGERDECLARATION_H

//
// Created by Jasmeet Brar on 2020-09-18.
//

#ifndef SIMPLE_C_COMPILER_INTEGERDECLARATION_H
#define SIMPLE_C_COMPILER_INTEGERDECLARATION_H

#include "Declaration.h"

namespace AST {

    class IntegerDeclaration : public Declaration {

    public:
        explicit IntegerDeclaration(Variable *variable);
        IntegerDeclaration(Variable *variable, Expression *value);
        void accept(Visitor *visitor) override;
    };

}


#endif //SIMPLE_C_COMPILER_INTEGERDECLARATION_H

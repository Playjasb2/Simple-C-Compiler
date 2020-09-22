//
// Created by Jasmeet Brar on 2020-09-18.
//

#ifndef SIMPLE_C_COMPILER_UNARYEXPRESSION_H
#define SIMPLE_C_COMPILER_UNARYEXPRESSION_H

#include <string>
#include "Expression.h"
#include "ASTPrinter.h"

using namespace std;

namespace AST {

    template<typename T>
    class UnaryExpression : public Expression {

    private:
        T subject;

    protected:
        explicit UnaryExpression(T subject) : subject(subject) {

        }

    public:
        T getSubject() {
            return this->subject;
        }

        void accept(ASTPrinter *printer) override {
            printer->visit(this);
        }
    };

}

#endif //SIMPLE_C_COMPILER_UNARYEXPRESSION_H

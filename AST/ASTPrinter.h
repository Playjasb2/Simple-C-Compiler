//
// Created by Jasmeet Brar on 2020-09-21.
//

#ifndef SIMPLE_C_COMPILER_ASTPRINTER_H
#define SIMPLE_C_COMPILER_ASTPRINTER_H

#include <string>


using namespace std;

namespace AST {

    class Statement;
    class StatementList;
    class AssignmentStatement;
    class IfStatement;
    class IntegerDeclaration;
    class IncrementDecrementExpression;
    class ArithmeticExpression;
    class ConditionalExpression;
    class FunctionCall;
    class NotExpression;
    class Expression;

    template<typename T>
    class UnaryExpression;

    class ASTPrinter {

    public:
        void visit(StatementList *statementList);
        void visit(AssignmentStatement *statement);
        void visit(IfStatement *statement);
        void visit(IntegerDeclaration *declaration);
        void visit(IncrementDecrementExpression *expression);
        void visit(ArithmeticExpression *expression);
        void visit(ConditionalExpression *expression);
        void visit(FunctionCall *functionCall);
        void visit(NotExpression *expression);
        void visit(UnaryExpression<string> *expression);
        void visit(UnaryExpression<Expression> *expression);

    };
}

#endif //SIMPLE_C_COMPILER_ASTPRINTER_H

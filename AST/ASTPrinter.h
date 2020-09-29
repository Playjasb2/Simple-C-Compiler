//
// Created by Jasmeet Brar on 2020-09-21.
//

#ifndef SIMPLE_C_COMPILER_ASTPRINTER_H
#define SIMPLE_C_COMPILER_ASTPRINTER_H

//#include <string>
//#include "Program.h"
//#include "AssignmentStatement.h"
//#include "IfStatement.h"
//#include "IntegerDeclaration.h"
//#include "IncrementDecrementExpression.h"
//#include "ArithmeticExpression.h"
//#include "FunctionCall.h"
//#include "NotExpression.h"

namespace AST {

    class ASTNode;
    class Expression;
    class Statement;
    class VariableStatement;
    class UnaryExpression;
    class BinaryExpression;
    class ArithmeticExpression;
    class ConditionalExpression;
    class Declaration;
    class Program;
    class StatementList;
    class AssignmentStatement;
    class IfStatement;
    class IntegerDeclaration;
    class IncrementDecrementExpression;
    class FunctionCall;
    class NotExpression;

    class ASTPrinter {

    public:
        void visit(Program *program);
        void visit(StatementList *statementList);
        void visit(AssignmentStatement *statement);
        void visit(IfStatement *statement);
        void visit(IntegerDeclaration *declaration);
        void visit(IncrementDecrementExpression *expression);
        void visit(ArithmeticExpression *expression);
        void visit(ConditionalExpression *expression);
        void visit(FunctionCall *functionCall);
        void visit(NotExpression *expression);
        void visit(UnaryExpression *expression);

    };
}

#endif //SIMPLE_C_COMPILER_ASTPRINTER_H

//
// Created by Jasmeet Brar on 2020-11-12.
//

#ifndef SIMPLE_C_COMPILER_VISITOR_H
#define SIMPLE_C_COMPILER_VISITOR_H

namespace AST {
    class Expression;

    class Statement;

    class VariableStatement;

    class UnaryExpression;

    class BinaryExpression;

    class ArithmeticExpression;

    class ConditionalExpression;

    class Program;

    class StatementList;

    class AssignmentStatement;

    class IfStatement;

    class IfBlock;

    class IntegerDeclaration;

    class IncrementDecrementExpression;

    class FunctionCall;

    class NotExpression;

    class ComputableExpression;
}

using namespace AST;

class Visitor {
public:
    virtual void visit(Program *program) = 0;
    virtual void visit(StatementList *statementList) = 0;
    virtual void visit(AssignmentStatement *statement) = 0;
    virtual void visit(IfStatement *statement) = 0;
    virtual void visit(IfBlock *ifblock) = 0;
    virtual void visit(IntegerDeclaration *declaration) = 0;
    virtual void visit(IncrementDecrementExpression *expression) = 0;
    virtual void visit(ArithmeticExpression *expression) = 0;
    virtual void visit(ConditionalExpression *expression) = 0;
    virtual void visit(FunctionCall *functionCall) = 0;
    virtual void visit(NotExpression *expression) = 0;
    virtual void visit(UnaryExpression *expression) = 0;
    virtual void visit(ComputableExpression *expression) = 0;

};

#endif //SIMPLE_C_COMPILER_VISITOR_H

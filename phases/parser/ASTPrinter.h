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

#include "../../lib/Visitor.h"

class ASTPrinter: public Visitor {
public:

    void visit(Program *program) override;
    void visit(StatementList *statementList) override;
    void visit(AssignmentStatement *statement) override;
    void visit(IfStatement *statement) override;
    void visit(IfBlock *ifblock) override;
    void visit(IntegerDeclaration *declaration) override;
    void visit(IncrementDecrementExpression *expression) override;
    void visit(ArithmeticExpression *expression) override;
    void visit(ConditionalExpression *expression) override;
    void visit(FunctionCall *functionCall) override;
    void visit(NotExpression *expression) override;
    void visit(UnaryExpression *expression) override;
    void visit(ComputableExpression *expression) override;

};

#endif //SIMPLE_C_COMPILER_ASTPRINTER_H

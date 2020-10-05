//
// Created by Jasmeet Brar on 2020-09-22.
//

#ifndef SIMPLE_C_COMPILER_PARSER_H
#define SIMPLE_C_COMPILER_PARSER_H

#include <vector>
#include <token.h>
#include <tokenStream.h>
#include <Program.h>
#include <StatementList.h>
#include <Statement.h>
#include <AssignmentStatement.h>
#include <IntegerDeclaration.h>
#include <IncrementDecrementExpression.h>
#include <IfStatement.h>
#include <IfBlock.h>
#include <FunctionCall.h>
#include <ArithmeticExpression.h>
#include <ConditionalExpression.h>
#include <NotExpression.h>


using namespace AST;

class parser {

private:
    static Program *program;
    static tokenStream *stream;
    static std::vector<std::string> *errors;

    static void addError(const std::string& custom);
    static void addError(const std::string& expected, Token *received);

    static StatementList *parseStatementList(bool isGlobalScope);
    static Statement *parseStatement();
    static AssignmentStatement *parseAssignmentStatement();
    static IntegerDeclaration *parseIntegerDeclaration();
    static IncrementDecrementExpression *parseIncrementDecrementExpression(bool isStatement);
    static IfStatement *parseIfStatement();
    static FunctionCall *parseFunctionCall(bool isStatement);

    static ArithmeticExpression *parseArithmeticExpression();
    static ConditionalExpression *parseConditionalExpression();

public:
    static Program *parseProgram(tokenStream *token_stream);


};


#endif //SIMPLE_C_COMPILER_PARSER_H

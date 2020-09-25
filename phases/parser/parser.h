//
// Created by Jasmeet Brar on 2020-09-22.
//

#ifndef SIMPLE_C_COMPILER_PARSER_H
#define SIMPLE_C_COMPILER_PARSER_H

#include <vector>
#include <token.h>
#include <tokenStream.h>
#include <Program.h>

using namespace std;
using namespace AST;

class parser {

private:
    static Program *program;
    static tokenStream *stream;
    static vector<string> *errors;

    static void addErrors(const string& error);

    static std::pair<StatementList, bool> parseStatementList();
    static std::pair<Statement, bool> parseStatement();
    static std::pair<Statement, bool> parseAssignmentStatement();
    static std::pair<Statement, bool> parseIntegerDeclaration();
    static std::pair<Statement, bool> parseIncrementDecrementExpression(bool isStatement);
    static std::pair<Statement, bool> parseIfStatement();
    static std::pair<Statement, bool> parseFunctionCall(bool isStatement);

public:
    static Program *parseStream(tokenStream *token_stream);


};


#endif //SIMPLE_C_COMPILER_PARSER_H

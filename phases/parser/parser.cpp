//
// Created by Jasmeet Brar on 2020-09-22.
//

#include <IntegerDeclaration.h>
#include <NullExpressionStatement.h>
#include "parser.h"

void parser::addErrors(const string& error) {
    parser::errors.push_back(error);
}

Program *parser::parseStream(tokenStream *token_stream) {
    parser::stream = token_stream;
    parser::errors = new vector<string>();
    std::pair<StatementList, bool> statementList = parseStatementList();

    if(!statementList.second) {
        string error = "Syntax Error: There are no statements in the program.\n";
        parser::addErrors(error);
    }

    parser::program = new Program(statementList.first, parser::errors);
    return parser::program;
}

std::pair<StatementList, bool> parser::parseStatementList() {
    StatementList statementList;
    std::pair<Statement, bool> statement = parseStatement();
    if(!statement.second) {
        string error = "Syntax Error: There are no valid statements in the program.\n";
        parser::addErrors(error);
        return std::pair(StatementList(), false);
    }

    std::pair<StatementList, bool> rest = parseStatementList();

    if(rest.second) {
        statementList = rest.first;
        statementList.addStatement(statement.first);
    }
    else {
        statementList = StatementList(statement.first);
    }

    return std::pair(statementList, true);
}

std::pair<Statement, bool> parser::parseStatement() {
    Token *current_token = parser::stream->peakNext();
    Token *second_token = parser::stream->peakNthNextToken(2);

    std::pair<Statement, bool> statement;

    switch (current_token->type) {
        case Token_Type::identifier:
            if(second_token->type == Token_Type::equal) {
                statement = parseAssignmentStatement();
            }
            else if(second_token->type == Token_Type::left_round_bracket) {
                statement = parseFunctionCall(true);
            }
            else {
                statement = parseIncrementDecrementExpression(true);
            }
            break;
        case Token_Type::int_type_keyword:
            statement = parseIntegerDeclaration();
            break;
        case Token_Type::plus_plus:
            statement = parseIncrementDecrementExpression(true);
            break;
        case Token_Type::minus_minus:
            statement = parseIncrementDecrementExpression(true);
            break;
        case Token_Type::if_:
            statement = parseIfStatement();
            break;
        default:
            statement = std::pair(NullExpressionStatement(), false);
            string error = "Syntax Error: Line " + to_string(current_token->line_number) + ":" +
                    to_string(current_token->position_number) + ": Expected Statement but got '" +
                    current_token->value + "'";
            parser::errors.push_back(error);
            break;
    }

    return statement;
}

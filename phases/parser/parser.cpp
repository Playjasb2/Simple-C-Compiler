//
// Created by Jasmeet Brar on 2020-09-22.
//

#include <IntegerDeclaration.h>
#include <map>
#include <algorithm>
#include "parser.h"

void parser::addError(const std::string& custom) {
    if(custom.empty()) {
        throw std::runtime_error("addError Error: Expected custom message");
        return;
    }

    parser::errors->push_back(custom);
}

void parser::addError(const std::string& expected, Token *received) {

    if(!(!expected.empty() && received)) {
        throw std::runtime_error("addError Error: Expected expected and received message");
        return;
    }

    std::string error = "Syntax Error: Line " + std::to_string(received->line_number) + ":" +
                        std::to_string(received->position_number) + ": Expected " + expected + " but got '" +
                        received->value + "'";
    parser::errors->push_back(error);
}


Program *parser::parseProgram(tokenStream *token_stream) {
    parser::stream = token_stream;
    parser::errors = new std::vector<std::string>();
    StatementList *statementList = parseStatementList(true);
    parser::program = new Program(statementList, parser::errors);
    return parser::program;
}

StatementList *parser::parseStatementList(bool isGlobalScope) {
    if(parser::stream->peakNext()->type == Token_Type::eof) {
        std::string error = "Syntax Error: There are no valid statements in the scope.\n";
        parser::addError(error);
        return nullptr;
    }

    Statement *statement = parseStatement();

    Token_Type next_token_type = parser::stream->peakNext()->type;

    if((isGlobalScope && next_token_type == Token_Type::eof) || (next_token_type == Token_Type::right_curly_bracket)) {
        //parser::stream->jump(1);
        return new StatementList(statement);
    }
    else {
        StatementList *rest = parseStatementList(isGlobalScope);
        rest->addStatement(statement);
        return rest;
    }
}

Statement *parser::parseStatement() {
    Token *current_token = parser::stream->peakNext();
    Token *second_token = parser::stream->peakNthToken(2);

    Statement *statement;

    switch (current_token->type) {
        case Token_Type::identifier:
            if(second_token->type == Token_Type::plus_plus || second_token->type == Token_Type::minus_minus) {
                statement = parseIncrementDecrementExpression(true);
            }
            else if(second_token->type == Token_Type::left_round_bracket) {
                statement = parseFunctionCall(true);
            }
            else {
                statement = parseAssignmentStatement();
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
            statement = nullptr;
            parser::addError("statement", current_token);
            break;
    }

    Token *semicolon_token = parser::stream->peakNext();

    if(statement && semicolon_token->type != Token_Type::semicolon) {
        parser::addError("semicolon", semicolon_token);
        statement = nullptr;
    }
    else {
        parser::stream->jump(1);
    }

    return statement;
}

AssignmentStatement *parser::parseAssignmentStatement() {
    Token *identifier = parser::stream->getNext();
    if(identifier->type != Token_Type::identifier) {
        parser::addError("identifier", identifier);
        return nullptr;
    }

    Token *assignment_operator = parser::stream->getNext();

    std::map<Token_Type, Assignment_Operator> possible_assignment_operators = {
            {Token_Type::equal, Assignment_Operator::equal},
            {Token_Type::plus_equal, Assignment_Operator::plus_equal},
            {Token_Type::minus_equal, Assignment_Operator::minus_equal},
            {Token_Type::multiply_equal, Assignment_Operator::multiply_equal},
            {Token_Type::divide_equal, Assignment_Operator::divide_equal}
    };

    auto *variable = new Variable(Type::Unknown, identifier);

    if(possible_assignment_operators.find(assignment_operator->type) == possible_assignment_operators.end()) {
        parser::addError("valid assignment operator", assignment_operator);
        return nullptr;
    }

    Assignment_Operator op = possible_assignment_operators.at(assignment_operator->type);

    Expression *expression = parseArithmeticExpression();

    auto *statement = new AssignmentStatement(variable, op, expression, assignment_operator);

    return statement;

}

IntegerDeclaration *parser::parseIntegerDeclaration() {
    Token_Type syntax[] = {Token_Type::int_type_keyword, Token_Type::identifier, Token_Type::equal};
    std::string syntax_strings[] = {"int keyword", "identifier", "'='"};
    auto processed_tokens = std::vector<Token *>();

    Token *current_token;

    for(int i = 0; i < syntax_strings->length(); i++) {
        current_token = parser::stream->getNext();
        if(current_token->type != syntax[i]) {
            parser::addError(syntax_strings[i], current_token);
            return nullptr;
        }
        processed_tokens.push_back(current_token);
    }

    Expression *expression = parseArithmeticExpression();

    processed_tokens.pop_back();
    processed_tokens.pop_back();

    IntegerDeclaration *declaration;

    auto *variable = new Variable(Type::Integer, processed_tokens.back());

    if(expression) {
        declaration = new IntegerDeclaration(variable, expression);
    }
    else {
        declaration = new IntegerDeclaration(variable);
    }

    return declaration;
}

IncrementDecrementExpression *parser::parseIncrementDecrementExpression(bool isStatement) {
    Token *current_token = parser::stream->getNext();
    IncrementDecrementOperator op;
    Variable *variable;
    if(current_token->type == Token_Type::plus_plus || current_token->type == Token_Type::minus_minus) {
        std::map<Token_Type, IncrementDecrementOperator> token_type_to_op = {
                {Token_Type::plus_plus, IncrementDecrementOperator::plus_plus_prefix},
                {Token_Type::minus_minus, IncrementDecrementOperator::minus_minus_prefix}
        };

        op = token_type_to_op.at(current_token->type);

        current_token = parser::stream->getNext();

        if(current_token->type == Token_Type::identifier) {
            variable = new Variable(Type::Integer, current_token);
        }
        else {
            parser::addError("some variable", current_token);
            return nullptr;
        }

        Token *next_token = parser::stream->peakNext();

        if(next_token->type == Token_Type::plus_plus || next_token->type == Token_Type::minus_minus) {
            std::string error = "Syntax Error: Line " + std::to_string(next_token->line_number) + ":"
                    + std::to_string(next_token->position_number) + ": Cannot have postfix '++' or '--' operator when "
                                                                    "there is already a prefix";
            parser::addError(error);
            parser::stream->jump(1);
            return nullptr;
        }

    }
    else if(current_token->type == Token_Type::identifier) {
        variable = new Variable(Type::Integer, current_token);

        current_token = parser::stream->getNext();

        if(current_token->type == Token_Type::plus_plus) {
            op = IncrementDecrementOperator::plus_plus_postfix;
        }
        else if(current_token->type == Token_Type::minus_minus) {
            op = IncrementDecrementOperator::plus_plus_postfix;
        }
        else {
            parser::addError("'++' or '--'", current_token);
            return nullptr;
        }
    }
    else {
        parser::addError("'++','--', or some variable", current_token);
        return nullptr;
    }

    auto * expression = new IncrementDecrementExpression(variable, op, isStatement);

    return expression;
}

IfStatement * parser::parseIfStatement() {
    std::vector<IfBlock *> *ifBlocks;
    Token_Type first_syntax[] = {Token_Type::if_, Token_Type::left_round_bracket};
    std::string first_syntax_strings[] = {"if", "("};

    Token *current_token;

    for(int i = 0; i < first_syntax_strings->length(); i++) {
        current_token = parser::stream->getNext();
        if(current_token->type != first_syntax[i]) {
            addError(first_syntax_strings[i], current_token);
            return nullptr;
        }
    }

    ConditionalExpression *conditionalExpression = parseConditionalExpression();

    Token_Type second_syntax[] = {Token_Type::right_round_bracket, Token_Type::left_curly_bracket};
    std::string second_syntax_strings[] {")", "{"};

    for(int i = 0; i < second_syntax_strings->length(); i++) {
        current_token = parser::stream->getNext();
        if(current_token->type != second_syntax[i]) {
            addError(second_syntax_strings[i], current_token);
            return nullptr;
        }
    }

    StatementList *statementList = parseStatementList(false);

    current_token = parser::stream->getNext();

    if(current_token->type != Token_Type::right_curly_bracket) {
        addError("}", current_token);
        return nullptr;
    }

    ifBlocks = new std::vector<IfBlock *>();
    auto *ifBlock = new IfBlock(conditionalExpression, statementList);
    ifBlocks->push_back(ifBlock);

    current_token = parser::stream->getNext();

    while(current_token->type == Token_Type::else_if_) {
        current_token = parser::stream->getNext();
        if(current_token->type != Token_Type::left_round_bracket) {
            addError("(", current_token);
            return nullptr;
        }

        conditionalExpression = parseConditionalExpression();

        for(int i = 0; i < second_syntax_strings->length(); i++) {
            current_token = parser::stream->getNext();
            if(current_token->type != second_syntax[i]) {
                addError(second_syntax_strings[i], current_token);
                return nullptr;
            }
        }

        statementList = parseStatementList(false);

        current_token = parser::stream->getNext();

        if(current_token->type != Token_Type::right_curly_bracket) {
            addError("}", current_token);
            return nullptr;
        }

        ifBlock = new IfBlock(conditionalExpression, statementList);
        ifBlocks->push_back(ifBlock);

        current_token = parser::stream->getNext();
    }

    if(current_token->type == Token_Type::else_) {
        current_token = parser::stream->getNext();
        if(current_token->type != Token_Type::left_curly_bracket) {
            addError("{", current_token);
            return nullptr;
        }

        statementList = parseStatementList(false);

        current_token = parser::stream->getNext();
        if(current_token->type != Token_Type::right_curly_bracket) {
            addError("}", current_token);
            return nullptr;
        }

        ifBlock = new IfBlock(statementList);
        ifBlocks->push_back(ifBlock);
    }

    std::reverse(ifBlocks->begin(), ifBlocks->end());

    auto *ifStatement = new IfStatement(ifBlocks);

    return ifStatement;
}
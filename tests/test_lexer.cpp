//
// Created by Jasmeet Brar on 2020-03-09.
//

#include "test_lexer.h"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <print.h>
#include <algorithm>
#include "lexer.h"


namespace po = boost::filesystem;

const char * token_type_names[] = {
    "integer",
    "string",
    "identifier",
    "semicolon",
    "if_",
    "else_if_",
    "else_",
    "and_",
    "or_",
    "not_",
    "equal",
    "plus",
    "minus",
    "multiply",
    "divide",
    "modulo",
    "plus_plus",
    "minus_minus",
    "plus_equal",
    "minus_equal",
    "multiply_equal",
    "divide_equal",
    "equal_equal",
    "not_equal",
    "greater_than",
    "less_than",
    "greater_than_or_equal_to",
    "less_than_or_equal_to",
    "bitwise_and",
    "bitwise_or",
    "bitwise_not",
    "bitwise_xor",
    "bitwise_and_equal",
    "bitwise_or_equal",
    "bitwise_not_equal",
    "bitwise_xor_equal",
    "left_shift",
    "right_shift",
    "left_round_bracket",
    "right_round_bracket",
    "left_curly_bracket",
    "right_curly_bracket",
    "int_keyword",
    "invalid",
    "eof"
};

bool lexer_tester::test_file(std::string filepath) {
    po::path p(filepath);

    std::string path_to_answers = p.parent_path().string() + "_answers/" + p.stem().string() + ".txt";

    std::ifstream current_stream;
    current_stream.open(path_to_answers);

    if(!current_stream.is_open()) {
        std::string message = "Error: Cannot open " + path_to_answers;
        print(message);
        return false;
    }

    tokenStream *token_stream = lexer::parsefile(filepath);

    std::vector<std::string> file_tokens;

    std::string line;

    while(getline(current_stream,line)) {

        if(line.empty()) continue;

        std::vector<std::string> result;

        int last_comma_index = line.find_last_of(',');

        std::string value = line.substr(0,last_comma_index);
        std::string type = line.substr(last_comma_index + 1);

        boost::trim(value);
        boost::trim(type);

        file_tokens.push_back(type);
        file_tokens.push_back(value);
    }

    reverse(file_tokens.begin(), file_tokens.end());

    Token *token;
    token = token_stream->getNext();

    bool errors = false;

    std::string type;
    std::string value;

    while(token) {

        if(file_tokens.size() >= 2) {
            type = file_tokens.back();
            file_tokens.pop_back();

            value = file_tokens.back();
            file_tokens.pop_back();
        }
        else {
            print("ERROR: Answer file doesn't have sufficient number of tokens");
            return false;
        }

        std::string error_message;

        if(token->value != value) {
            errors = true;

            error_message = "Error on line " + std::to_string(token->line_number) + "," +
                                   std::to_string(token->position_number) + ": ";
            error_message += "Value mismatch; token value " + token->value + " does not match " + value;

            print(error_message);
        }

        if(token_type_names[(int) token->type - 1] != type) {
            errors = true;

            error_message = "Error on line " + std::to_string(token->line_number) + "," +
                            std::to_string(token->position_number) + ": ";
            error_message += "Type mismatch; token type " + std::string(token_type_names[(int) token->type - 1]) +
                    " does not match " + type;

            print(error_message);

        }

        token = token_stream->getNext();
    }


    return !errors;
}
//
// Created by Jasmeet Brar on 2019-12-31.
//

#include <utility>
#include "lexer.h"



tokenStream *lexer::parsefile(std::string filename){
    std::ifstream fileStream;

    std::string line;

    std::string current_value;

    tokenizer tokenizer;

    tokenizer.process_file(std::move(filename));

    return tokenizer.get_token_stream();
}
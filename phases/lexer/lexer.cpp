//
// Created by Jasmeet Brar on 2019-12-31.
//
#include <string>
#include <utility>
#include <vector>

#include "lexer.h"


using namespace std;

tokenStream *lexer::parsefile(string filename){
    ifstream fileStream;

    string line;

    string current_value;

    tokenizer tokenizer;

    tokenizer.process_file(std::move(filename));

    return tokenizer.get_token_stream();
}
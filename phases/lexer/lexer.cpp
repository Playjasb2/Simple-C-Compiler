//
// Created by Jasmeet Brar on 2019-12-31.
//
#include <string>
#include <vector>

#include "lexer.h"


using namespace std;

tokenStream *lexer::parsefile(char **filename){
    ifstream fileStream;

    string line;

    string current_value;

    tokenizer tokenizer;

    tokenizer.process_file((string) *filename);

    return tokenizer.get_token_stream();
}
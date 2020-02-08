//
// Created by Jasmeet Brar on 2019-12-31.
//
#include <string>
#include <vector>

#include "lexer.h"


using namespace std;

vector<Token> *lexer::parsefile(char **filename){
    ifstream fileStream;

    string line;

    string current_value;

    vector<Token> *tokens;

    tokenizer tokenizer;

    tokenizer.process_file((string) *filename);

    return tokens;
}
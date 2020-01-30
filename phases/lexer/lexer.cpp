//
// Created by Jasmeet Brar on 2019-12-31.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "tokenizer.h"


using namespace std;

vector<Token> *parsefile(char **filename){
    ifstream fileStream;

    //fileStream.open((const char *) *filename);

    string line;

    string current_value;

    vector<Token> *tokens;

    tokenizer tokenizer;

    tokenizer.process_file((string) *filename);

    return tokens;
}
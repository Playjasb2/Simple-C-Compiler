//
// Created by Jasmeet Brar on 2020-01-12.
//

#ifndef COMPILER_PROJECT_TOKENIZER_H
#define COMPILER_PROJECT_TOKENIZER_H

#endif //COMPILER_PROJECT_TOKENIZER_H

#include <string>
#include <iostream>
#include <fstream>

#include <tokenStream.h>
#include <print.h>

using namespace std;

class tokenizer {

    int line_number = 0;
    int position_number = 0;
    const char *line_char;
    string current_stream_name;
    ifstream current_stream;

public:
    void process_file(string filename);
    void read_current_file();
    void read_identifier();
    void read_number();
    void read_string();
    void read_comment();
};
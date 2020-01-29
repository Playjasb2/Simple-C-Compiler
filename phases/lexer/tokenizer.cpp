//
// Created by Jasmeet Brar on 2020-01-12.
//

#include <string>
#include <iostream>
#include <utility>

#include "tokenizer.h"

using namespace std;

void tokenizer::process_file(string filename) {
    current_stream_name = move(filename);
    current_stream.open(current_stream_name);

    if(current_stream.is_open()) {
        read_current_file();
    }
    else {
        print("Cannot open " + current_stream_name);
    }

}

void tokenizer::read_current_file() {
    string line;

    line_number = 0;
    position_number = 0;

    while(getline(current_stream, line)) {
        print(line);

        line_number++;
        position_number++;

        line_char = line.c_str();

        while(*line_char != '\0') {
            print(*line_char);
            line_char++;
        }
    }
}

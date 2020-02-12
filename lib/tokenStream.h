//
// Created by Jasmeet Brar on 2020-01-26.
//

#ifndef JAS_COMPILER_TOKENSTREAM_H
#define JAS_COMPILER_TOKENSTREAM_H

#include <token.h>
#include <vector>

class tokenStream {

private:

    vector<Token> *stream;
    int current_index = -1;
    unsigned int length = 0;

public:

    explicit tokenStream(vector<Token> *stream);
    Token *getNext();
    Token *getPrevious();
    Token *peakNext();
    Token *peakPrevious();

    unsigned int get_length();

};

#endif //JAS_COMPILER_TOKENSTREAM_H

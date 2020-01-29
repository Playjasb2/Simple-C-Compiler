//
// Created by Jasmeet Brar on 2020-01-26.
//

#ifndef JAS_COMPILER_TOKENSTREAM_H
#define JAS_COMPILER_TOKENSTREAM_H

#endif //JAS_COMPILER_TOKENSTREAM_H

#include <token.h>
#include <vector>

class tokenStream {

private:

    vector<Token> *stream;
    int current_index = -1;

public:

    tokenStream(vector<Token> *stream);
    Token *getNext();
    Token *getPrevious();
    Token *peakNext();
    Token *peakPrevious();

};

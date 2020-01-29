//
// Created by Jasmeet Brar on 2020-01-28.
//

#include "tokenStream.h"

tokenStream::tokenStream(vector<Token> *stream) {
    this->stream = stream;
}

Token *tokenStream::getNext() {
    return &this->stream->at(++this->current_index);
}

Token *tokenStream::getPrevious() {
    return &this->stream->at(--this->current_index);
}

Token *tokenStream::peakNext() {
    return &this->stream->at(this->current_index + 1);
}

Token *tokenStream::peakPrevious() {
    return &this->stream->at(this->current_index - 1);
}

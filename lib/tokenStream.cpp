//
// Created by Jasmeet Brar on 2020-01-28.
//

#include "tokenStream.h"

tokenStream::tokenStream(vector<Token> *stream) {
    this->stream = stream;
    this->length = stream->size();
}

Token *tokenStream::getNext() {
    if(this->current_index + 1 >= this->length) {
        return nullptr;
    }
    return &this->stream->at(++this->current_index);
}

Token *tokenStream::getPrevious() {
    if(this->current_index - 1 < 0) {
        return nullptr;
    }
    return &this->stream->at(--this->current_index);
}

Token *tokenStream::peakNext() {
    if(this->current_index + 1 >= this->length) {
        return nullptr;
    }
    return &this->stream->at(this->current_index + 1);
}

Token *tokenStream::peakPrevious() {
    if(this->current_index - 1 < 0) {
        return nullptr;
    }
    return &this->stream->at(this->current_index - 1);
}

unsigned int tokenStream::get_length() const {
    return this->length;
}
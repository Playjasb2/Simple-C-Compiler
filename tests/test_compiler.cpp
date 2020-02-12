//
// Created by Jasmeet Brar on 2020-01-04.
//

#include <iostream>
#include "test_compiler.h"

#include "lexer.h"

using namespace std;

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    tokenStream * token_stream = lexer::parsefile(&filename);

    if(token_stream == nullptr) return 1;

    for(unsigned int i = 0; i < token_stream->get_length(); i++) {
        Token *token = token_stream->getNext();
        if(token->type == Token_Type::eof) return 0;
        print(token->value);
    }

    return 0;

}

//
// Created by Jasmeet Brar on 2020-02-08.
//

#ifndef SIMPLE_C_COMPILER_LEXER_H
#define SIMPLE_C_COMPILER_LEXER_H

#include "tokenizer.h"

namespace lexer {
    tokenStream *parsefile(std::string filename);

}

#endif //SIMPLE_C_COMPILER_LEXER_H

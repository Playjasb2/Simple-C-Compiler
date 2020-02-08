//
// Created by Jasmeet Brar on 2020-01-04.
//

#include <iostream>
#include "test_compiler.h"

#include "lexer.h"

using namespace std;

int main(int argc, char *argv[]) {
    char *filename = "./test_cases/test.jas";

    lexer::parsefile(&filename);

}

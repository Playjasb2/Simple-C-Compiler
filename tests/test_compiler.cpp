//
// Created by Jasmeet Brar on 2020-01-04.
//

#include <iostream>
#include "test_compiler.h"

#include "lexer.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Hello World" << endl;

    char *filename = "./test_cases/test.jas";

    parsefile(&filename);

}

//
// Created by Jasmeet Brar on 2020-01-23.
//

#ifndef COMPILER_PROJECT_PRINT_H
#define COMPILER_PROJECT_PRINT_H

#include <iostream>

template <typename T>
void inline print(const T& output) {
    std::cout << output << std::endl;
}

#endif //COMPILER_PROJECT_PRINT_H
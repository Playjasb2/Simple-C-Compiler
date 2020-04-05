//
// Created by Jasmeet Brar on 2020-01-04.
//

#ifndef COMPILER_PROJECT_TEST_COMPILER_H
#define COMPILER_PROJECT_TEST_COMPILER_H

#include <vector>
#include <string>
#include <algorithm>

#define exists_in_set(needle, haystack) std::find(std::begin(haystack), std::end(haystack), needle) != std::end(haystack)

using namespace std;

namespace tester {
    const char *test_mode[] = {"lexer", "parser", "semantics", "codegen", "optimization"};
}

#endif //COMPILER_PROJECT_TEST_COMPILER_H

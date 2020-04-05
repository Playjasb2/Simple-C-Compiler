add_executable(tester
        test_compiler.cpp
        test_compiler.h
        test_lexer.cpp
        test_lexer.h)

FILE(COPY ./test_cases DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
FILE(COPY ./test_cases_answers DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
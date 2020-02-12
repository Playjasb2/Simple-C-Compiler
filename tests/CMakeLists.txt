add_executable(tester test_compiler.cpp test_compiler.h)

FILE(COPY ./test_cases DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
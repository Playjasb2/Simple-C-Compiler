add_executable(tester test_compiler.cpp test_compiler.h)

#target_include_directories(tester PRIVATE ../compiler)

FILE(COPY ./test_cases DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
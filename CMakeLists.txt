cmake_minimum_required(VERSION 3.15)
project(Simple-C-Compiler VERSION 0.01)

set(CMAKE_CXX_STANDARD 20)

set(COMPILER_VERSION ${PROJECT_VERSION})

set(Boost_USE_MULTITHREADED TRUE)

set(REQUIRED_BOOST_LIBRARIES
        program_options
        filesystem
        )

FIND_PACKAGE( Boost 1.72.0 REQUIRED COMPONENTS ${REQUIRED_BOOST_LIBRARIES} REQUIRED )

include_directories(${Boost_INCLUDE_DIRS})

add_library(include INTERFACE)
target_include_directories(include INTERFACE include/)

add_subdirectory(lib)
add_subdirectory(AST)
add_subdirectory(phases)
add_subdirectory(compiler)
add_subdirectory(tests)

target_link_libraries(compiler include lexer parser)
target_link_libraries(tester lexer parser)

target_link_libraries(compiler ${Boost_LIBRARIES})
target_link_libraries(tester ${Boost_LIBRARIES})

add_compile_options(-Wall -O2)
set_target_properties(compiler PROPERTIES OUTPUT_NAME Simple-C)
install(TARGETS compiler RENAME Simple-C DESTINATION bin)

enable_testing()

add_test(NAME lexer_arithmetics COMMAND tester -m lexer "./test_cases/arithmetics.jas" WORKING_DIRECTORY ./tests)
add_test(NAME lexer_comments COMMAND tester -m lexer "./test_cases/comments.jas" WORKING_DIRECTORY ./tests)
add_test(NAME lexer_printf COMMAND tester -m lexer "./test_cases/printf.jas" WORKING_DIRECTORY ./tests)
add_test(NAME lexer_conditionals COMMAND tester -m lexer "./test_cases/conditionals.jas" WORKING_DIRECTORY ./tests)
add_test(NAME lexer_instantiate_int COMMAND tester -m lexer "./test_cases/instantiate_int.jas" WORKING_DIRECTORY
        ./tests)
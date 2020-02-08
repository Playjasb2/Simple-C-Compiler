cmake_minimum_required(VERSION 3.15)
project(Simple-C-Compiler VERSION 0.01)

set(CMAKE_CXX_STANDARD 20)

set(COMPILER_VERSION ${PROJECT_VERSION})

add_library(include INTERFACE)
target_include_directories(include INTERFACE include/)

add_subdirectory(lib)
add_subdirectory(phases)
add_subdirectory(compiler)
add_subdirectory(tests)

target_link_libraries(compiler include lexer)
target_link_libraries(tester lexer)

add_compile_options(-Wall)
set_target_properties(compiler PROPERTIES OUTPUT_NAME Simple-C)
install(TARGETS compiler RENAME Simple-C DESTINATION bin)
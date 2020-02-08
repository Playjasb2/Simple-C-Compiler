add_library(
        lexer
        lexer.cpp
        lexer.h
        tokenizer.cpp
        tokenizer.h)

target_include_directories(lexer PUBLIC ".")

target_link_libraries(lexer lib)

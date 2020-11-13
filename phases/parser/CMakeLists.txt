add_library(
        parser
        parser.h
        parser.cpp
        ASTPrinter.h
        ASTPrinter.cpp
)

target_include_directories(parser PUBLIC ".")

target_link_libraries(parser lib AST)
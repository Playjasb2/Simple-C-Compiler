add_library(
        lib
        tokenStream.h
        tokenStream.cpp Visitor.h)

target_include_directories(lib PUBLIC ".")

target_link_libraries(lib include)
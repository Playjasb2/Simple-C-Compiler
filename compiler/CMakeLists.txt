configure_file(main.h.in main.h)

add_executable(compiler main.cpp main.h.in)

target_include_directories(compiler PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
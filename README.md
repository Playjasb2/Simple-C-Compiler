# Simple C Compiler

As a side project, I have decided to build a compiler that would compile a simplified version of C, that I call "Simple C", to x86-64.

As of right now, the definition of this language isn't fully layed out, since more features will be added overtime. Simple C is currently "headerless", as I'm not going to process header files from the start. This means, for the language to do anything particularly useful, such as printing to stdout or taking input with stdin, I will make the assumption that those behaviours are defined, as if `stdio.h` is built-in. Over time, this may subject to change.

Note: I have only tested the compiler on macOS and Linux; I have not tested it on Windows.

## Getting Started


### Prerequisites

In order to compile the compiler and optionally install it in your system, you need the following installed in your system:

- g++ compiler that can compile C++20 source code
- CMake version 3.15 or later

[CMake](https://cmake.org) is a build system that I decided to use that would work cross-platform, and I found it to be quite useful for large projects, such as this, in order to help me easily define my build pipeline.

### Building and Installing the Compiler

Once you have those prerequisites and you have cloned the repository, go into the repository using the Terminal, and execute the following commands:

```
mkdir build
cd build
cmake ../
```

This will make a build directory in the repo folder, and `cd` into it. And then running the `cmake` command on the parent folder will bring compiler source files into the build folder and generate a Makefile, based on the build pipeline that I have defined in my CMakeLists.txt files that I have, throughout my project.

To build the executables, you just need to execute `make` while you're in the build folder, and it will generate the executables for both the compiler, and the test program for it.

You can optionally install the compiler in your system, if you wish to. You just need to execute `make install`, and it will install the `Simple-C` in the bin location of your system. Typically it would install it in a location like `/usr/local/bin/Simple-C`.

## Testing

As of right now, I have not finished setting up a pipeline for testing. I currently have a test program that would look a specific test file, and run the lexer on it. I still have to set up more test cases that would test how each phases of the compiler interpret each feature of the source language. I also plan to test everything using CTest, and have CI be used in this project, where I may use Github Actions to automate the testing that would be done, every time I commit to the repo.
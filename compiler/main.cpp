#include <iostream>
#include <unistd.h>
#include <algorithm>

#include "main.h"
#include "lexer.cpp"

using namespace std;

void print_usage() {
    cout << "USAGE:" << endl;
    cout << "-h : display this message" << endl;
    cout << "-D : [lexer/parser/semantics/codegen/optimizer] : debug options" << endl;
    cout << "-v : get version number" << endl;
}

void print_version() {
    cout << "Jas Compiler Version: " << COMPILER_VERSION << endl;
}

int main(int argc, char *argv[]) {

    int op = 0;
    char *debug_option = nullptr;
    char *filename = nullptr;

    if(argc == 1) {
        print_usage();
        return 0;
    }


    if(argc > 1 && argv[1][0] != '-') {
        filename = argv[1];
        optind++;
    }

    while((op = getopt(argc, argv, "hvD:")) != -1)
    {
        switch(op)
        {
            case 'D':
            {
                debug_option = optarg;
                break;
            }
            case 'v':
            {
                print_version();
                return 0;
            }

            default:
            {
                print_usage();
                return 0;
            }

        }
    }

    if(debug_option != nullptr and find(begin(DEBUG_OPTIONS), end(DEBUG_OPTIONS), string(debug_option)) == end(DEBUG_OPTIONS)) {
        print_usage();
        return 0;
    }

    if(filename) {
        parsefile(&filename);
    }

    return 0;
}

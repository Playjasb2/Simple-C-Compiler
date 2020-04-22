#include <iostream>
#include <algorithm>
#include <boost/program_options.hpp>
#include "main.h"
#include "lexer.h"

using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[]) {

    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "produce help message")
            ("version,v", "compiler version")
            ("input-file", po::value< vector<string> >(), "input file")
            ;

    po::positional_options_description p;
    p.add("input-file", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).
            options(desc).positional(p).run(), vm);
    po::notify(vm);

    if(vm.count("version")) {
        print("Jas Compiler Version: " + to_string(COMPILER_VERSION));
    }
    else if(vm.count("input-file")) {
        string filepath = vm["input-file"].as< vector<string> >().front();

        // Lexical Analysis
        tokenStream *token_stream = lexer::parsefile(filepath);

        // Syntax Analysis

        // Semantics Analysis

        // Intermediate Representation

        // Optimization

        // Code Generation
    }
    else {
        print("USAGE: ./Simple-C <FLAGS> <path to file>");
        print("FLAGS:");
        print("\t-help/-h : display this message");
        print("\t-version/-v : get compiler version");
    }

    return 0;
}

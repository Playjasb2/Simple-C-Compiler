//
// Created by Jasmeet Brar on 2020-01-04.
//

#include <vector>
#include "test_compiler.h"
#include <boost/program_options.hpp>
#include "lexer.h"
#include "test_lexer.h"


using namespace tester;
namespace po = boost::program_options;

int main(int argc, char *argv[]) {

    po::options_description desc("Allowed options");
    desc.add_options()
            ("help,h", "produce help message")
            ("mode,m", po::value<std::string>(), "mode")
            ("input-file", po::value< std::vector<std::string> >(), "input file")
            ;

    po::positional_options_description p;
    p.add("input-file", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).
            options(desc).positional(p).run(), vm);
    po::notify(vm);

    if (vm.count("input-file") && vm.count("mode")) {
        std::string filepath = vm["input-file"].as< std::vector<std::string> >().front();
        std::string mode = vm["mode"].as<std::string>();

        if(!(exists_in_set(mode, test_mode))) {
            return 1;
        }

        // Handle file
        bool result = lexer_tester::test_file(filepath);

        if(result) {
            print("PASS");
        }
        else {
            print("FAIL");
            return 1;
        }
    }
    else {
        print("USAGE: ./tester <flags> <test file>");
        print("FLAGS:");
        print("\t-help/-h : display this message");
        print("\t-mode/-m : [lexer/parser/semantics/codegen/optimizer]");
    }

    return 0;

}

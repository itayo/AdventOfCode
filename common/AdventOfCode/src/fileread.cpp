#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
#include "../inc/fileread.h"

namespace aoc {


    std::vector<std::string> ReadFile(std::string file_path) {
        std::ifstream file(file_path);
        std::string line;
        std::vector<std::string> v;
        while (std::getline(file,line)) {
            // Now keep reading next line
            // and push it in vector function until end of file
            v.push_back(line);
        }
        return v;
    }

    std::vector<std::string> Tokenize(std::string line) {
        std::vector<std::string> tokens;
        std::stringstream check(line);
        std::string intermediate;
        while (std::getline(check, intermediate, ' ')) {
            tokens.push_back(intermediate);
        }
        return tokens;
    }
}
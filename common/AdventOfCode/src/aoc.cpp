#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include "../inc/aoc.h"


    std::vector<std::string> AoC::ReadFile(std::string file_path) {
        std::ifstream file(file_path);
        std::string line;
        std::vector<std::string> v;
        while (std::getline(file,line)) {
            v.push_back(line);
        }
        return v;
    }

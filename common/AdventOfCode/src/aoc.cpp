#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
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

std::vector<std::string> AoC::StringSplit(std::string line, char delimiter) {
    std::string part;
    std::vector<std::string> result;
    std::stringstream stream(line);
    while(std::getline(stream, part, delimiter)) {
        result.push_back(part);
    }
    return result;
}

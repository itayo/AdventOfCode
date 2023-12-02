#ifndef ADVENTOFCODE_LIB_H
#define ADVENTOFCODE_LIB_H
#include <vector>
#include <string>
    class AoC {
    public:
        std::vector<std::string> ReadFile(std::string file);
        std::vector<std::string> StringSplit(std::string line, char delimiter);
    };
#endif

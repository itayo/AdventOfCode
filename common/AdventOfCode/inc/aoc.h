#ifndef ADVENTOFCODE_LIB_H
#define ADVENTOFCODE_LIB_H
#include <vector>
#include <string>
namespace AoC {
    struct tStringToReplace {
        tStringToReplace(){}
        tStringToReplace(std::string a, std::string b) : what(a), withWhat(b){}

        std::string what;
        std::string withWhat;
    };
    class AoC {
    public:
        std::vector<std::string> ReadFile(std::string file);

        std::vector<std::string> StringSplit(std::string line, char delimiter);
        void StringReplace(std::string &string, std::vector<tStringToReplace> replacers);
        void StringReplace(std::vector<std::string> &strings, std::vector<tStringToReplace> replacers);
    };
}
#endif

#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
#include "../inc/aoc.h"

namespace AoC {
    std::vector<std::string> AoC::ReadFile(std::string file_path) {
        std::ifstream file(file_path);
        std::string line;
        std::vector<std::string> v;
        while (std::getline(file, line)) {
            v.push_back(line);
        }
        return v;
    }

    std::vector<std::string> AoC::StringSplit(std::string &line, char delimiter) {
        std::string part;
        std::vector<std::string> result;
        std::stringstream stream(line);
        while (std::getline(stream, part, delimiter)) {
            result.push_back(part);
        }
        return result;
    }

    void AoC::StringReplace(std::string &line, std::vector<tStringToReplace> replacers) {
        for (tStringToReplace replacer: replacers) {
            size_t pos = 0;
            while ((pos = line.find(replacer.what)) != std::string::npos) {
                line.replace(pos, replacer.what.length(), replacer.withWhat);
            }
        }

    }
    void AoC::StringReplace(std::vector<std::string> &lines, std::vector<tStringToReplace> replacers) {
        for(size_t i=0; i < lines.size(); i++) {
            StringReplace(lines[i], replacers);
        }

    }
}


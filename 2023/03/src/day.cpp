#include <iostream>
#include "day.h"


void Day::PrepareData() {

}

bool Day::CheckGrid(int line, int pos, int len) {
    bool valid = false;
    std::vector<AoC::position> offsetsToCheck;
    for (int i = -1; i <= len; i++) {
        offsetsToCheck.push_back({line - 1, pos + i});
        offsetsToCheck.push_back({line, pos + i});
        offsetsToCheck.push_back({line + 1, pos + i});
    }
    std::string check;
    for (auto offset: offsetsToCheck) {
        if (m_grid.Exists(offset)) {
            char c = m_grid.Get(offset);
            if(c != '.' && !std::isdigit(c)) {
                return true;
            }
        }
    }
    return valid;
}

bool Day::CheckGrid2(int line, int pos, int len) {
    bool valid = false;
    int startLine = line, stopLine = line;
    int startPos = pos, stopPos = pos + len;
    if (line != 0) startLine -= 1;
    if (line < m_data.size() - 1) stopLine += 1;
    if (startPos != 0) startPos -= 1;
    if (stopPos < m_data[line].length() - 1) stopPos += 1;
    for (size_t currLine = startLine; currLine <= stopLine; currLine++) {
        for (size_t currPos = startPos; startPos <= stopPos; currPos++) {
            if (m_data[currLine][currPos] != '.' && !std::isdigit(m_data[currLine][currPos])) {
                return true;
            }
        }

    }
    return false;
}


void Day::RunA(bool secondData) {
    m_resultA = 0;
    std::regex rx("(\\d+)");
    std::smatch match;
    for (size_t i = 0; i < m_data.size(); i++) {
        std::string str = m_data[i].substr(0, m_data[i].length());
        while (regex_search(str, match, rx)) {
            size_t start = m_data[i].find(match[1].str());
            int value = std::stoi(match[1].str());
            if (CheckGrid(i, start, match[1].str().length())) {
                m_resultA += value;
            }
            str = match.suffix().str();
        }
    }

}

void Day::RunB() {

}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
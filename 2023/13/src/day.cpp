#include <iostream>
#include <thread>
#include <future>
#include "day.h"

void Day::PrepareData() {
    std::vector<std::string> cache;
    for (auto data: m_data) {
        if (data == "") {
            CreateMap(cache);
            cache.clear();
        } else {
            cache.emplace_back(data);
        }
    }
    CreateMap(cache);
}

void Day::CreateMap(std::vector<std::string> cache) {
    const int rows = cache.size();
    const int columns = cache[0].size();
    Maps maps;
    std::string temp = "";
    temp.append(" ", rows);
    std::vector<std::string> cache2(columns, temp);
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            cache2[i][j] = cache[j][i];
        }
    }
    maps.origin = cache;
    maps.transposed = cache2;
    m_mapsA.emplace_back(maps);
    m_mapsB.emplace_back(maps);


}

int Day::TryFindMirrorLocation(std::vector<std::string> &map, bool findSmudge) {
    for (int i = 1; i < map.size(); ++i) {
        if (IsMirrored(map, i, findSmudge)) return i;
    }
    return -1;
}

std::pair<bool, bool> Day::StringChecker(std::string left, std::string right) {
    uint64_t leftSize = left.size();
    uint64_t rightSize = right.size();
    uint64_t fails = leftSize > rightSize? leftSize-rightSize: rightSize-leftSize;
    for (int index = 0; index < left.size() && index < right.size() && fails < 2; ++index) {
        fails += (left[index] != right[index]);
    }

    return {fails == 0, fails == 1};
}


bool Day::IsMirrored(std::vector<std::string> &map, int right, bool findSmudge) {
    if (right < 0 || right >= map.size()) return false;
    int left = right - 1;
    bool smudgeFound = false;
    while (left >= 0 && right < map.size()) {
        auto checkedString = StringChecker(map[left], map[right]);
        bool stringMatches = checkedString.first;
        bool isDirty = checkedString.second;
        if (findSmudge) {
            if (!stringMatches && !isDirty) return false;
            if (isDirty && smudgeFound) return false;
            if (isDirty) smudgeFound =true;

        } else {
            if (!stringMatches) return false;
        }
        --left;
        ++right;
    }
    if (!findSmudge) return true;
    return smudgeFound;
}

void Day::Runner(std::vector<Maps> &maps, uint64_t &result, bool findSmudge) {
    int rows = 0;
    int columns = 0;
    for (int index = 0; index < m_mapsA.size(); ++index) {
        auto &map = maps[index];
        int centerColumn = TryFindMirrorLocation(map.transposed, findSmudge);
        int centerRow = TryFindMirrorLocation(map.origin, findSmudge);
        if (centerColumn != -1) {
            result += centerColumn;
        }
        if (centerRow != -1) {
            result += 100 * (centerRow);
        }
    }
}

void Day::RunA(bool secondData) {
    Runner(m_mapsA, m_resultA);
}


void Day::RunB() {
    m_mapsB.clear();
    m_mapsB.insert(m_mapsB.end(), m_mapsA.begin(), m_mapsA.end());
    Runner(m_mapsB, m_resultB, true);


}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
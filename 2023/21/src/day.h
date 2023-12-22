#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include "AoC/aoc.h"
#include <list>
#include "AoC/Grid2D.h"

class Day {
public:

    Day(std::vector<std::string> data)
            : m_resultA(0), m_resultB(0), m_data(data), m_mapA(data.size(), data[0].size()) {
        for(int row=0;row < data.size();++row) {
            for(int column=0; column < data[row].size();++column) {
                m_mapA.Set(row, column, data[row][column]);
            }
        }
        m_start = m_mapA.FindPos('S');
    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }


private:
    uint64_t Walk(uint64_t distance=65);

    AoC::AoC aoc;
    AoC::Grid2D<char> m_mapA;
    AoC::Vector2D m_start{0,0};
    const std::vector<std::string> m_data;
    uint64_t m_resultA;
    uint64_t m_resultB;
};

#endif //ADVENTOFCODE_DAY_H

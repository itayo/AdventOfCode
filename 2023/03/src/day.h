#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H
#include <vector>
#include <aoc.h>
#include <string>
#include <regex>
#include "Grid2D.h"


class Day {
public:
    Day(std::vector<std::string> data) : m_resultA(0), m_resultB(0), m_data(data) {
        m_grid = AoC::Grid2D<char>(m_data.size(), m_data[0].size());
        for(int row=0; row < m_data.size(); row++) {
            for(int col=0; col < m_data[row].size(); col++)
            {
                m_grid.Set(row,col,m_data[row][col]);
            }
        }
    }
    void PrepareData();
    void RunA(bool secondData = false);
    void RunB();
    void Report();
    int ResultA() { return m_resultA; }
    int ResultB() { return m_resultB; }
private:
    std::string CleanString(std::string line);
    bool CheckGrid(int line, int pos, int len);
    bool CheckGrid2(int line, int pos, int len);
    AoC::AoC aoc;
    std::vector<std::string> m_data;
    AoC::Grid2D<char> m_grid;
    int m_resultA;
    int m_resultB;
};


#endif //ADVENTOFCODE_DAY_H

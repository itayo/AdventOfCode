#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H
#include <vector>
#include <aoc.h>

class Day {
public:
    Day(std::vector<std::string> data) : m_resultA(0), m_resultB(0), m_data(data) {}
    void PrepareData();
    void RunA(bool secondData = false);
    void RunB();
    void Report();
    int ResultA() { return m_resultA; }
    int ResultB() { return m_resultB; }
private:
    std::string CleanString(std::string line);
    AoC::AoC aoc;
    std::vector<std::string> m_data;
    int m_resultA;
    int m_resultB;
};


#endif //ADVENTOFCODE_DAY_H

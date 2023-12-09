#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include <aoc.h>
#include <list>


class Day {
public:
    Day(std::vector<std::string> data)
            : m_resultA(0), m_resultB(0), m_data(data) {
    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }

private:
    int CalculateSequence(const std::vector<int> &numbers, bool backwards = false);

    AoC::AoC aoc;
    const std::vector<std::string> m_data;
    std::vector<std::vector<int>> m_sequence;
    uint64_t m_resultA;
    uint64_t m_resultB;
    int m_lr = 0;
};

#endif //ADVENTOFCODE_DAY_H

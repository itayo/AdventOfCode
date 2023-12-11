#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include <aoc.h>
#include <list>
#include "Grid2D.h"
template <typename T>
bool IsInBounds(const T& value, const T& a, const T& b) {
    return !(value < std::min(a,b)) && (value < std::max(a,b));
}

class Day {
public:

    Day(std::vector<std::string> data)
            : m_resultA(0), m_resultB(0), m_data(data), m_map(0,0) {
    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }

    struct Vector2DPair{
        Vector2DPair(AoC::Vector2D p_start, AoC::Vector2D p_stop) :start(p_start), stop(p_stop), steps(0){}
        Vector2DPair(AoC::Vector2D p_start, AoC::Vector2D p_stop, int p_steps) :start(p_start), stop(p_stop), steps(p_steps){}
        AoC::Vector2D start;
        AoC::Vector2D stop;
        uint64_t steps;
    };

private:
    void Calculate(std::vector<Vector2DPair> &p_pairs, uint64_t expansion);
    AoC::AoC aoc;
    const std::vector<std::string> m_data;
    std::vector<int> m_expansionX;
    std::vector<int> m_expansionY;
    AoC::Grid2D<char> m_map;
    std::vector<Vector2DPair> m_pairsA;
    uint64_t m_resultA;
    uint64_t m_resultB;
    int m_lr = 0;
};

#endif //ADVENTOFCODE_DAY_H

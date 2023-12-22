#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include "AoC/aoc.h"
#include <AoC/Vector2D.h>
#include <AoC/Grid2D.h>

class Day {
public:

    enum tSignal {
        low = 0,
        hi = 1
    };
    enum class tTypes {
        Broadcast,
        FlipFlop,
        Conjunction,
        none
    };
    struct tModules {
        std::string name;

    };

    Day(std::vector<std::string> data)
            : m_resultA(0), m_resultB(0), m_data(data), m_goalPoseA(data.front().size() - 1, data.size() - 1),
              m_heatMap(data.front().size(), data.size()) {
        for (size_t row = 0; row < data.size(); ++row) {
            for (size_t column = 0; column < data.front().size(); ++column) {
                m_heatMap.Set(row, column, data[row][column] - '0');
            }
        }
    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }


private:

    AoC::AoC aoc;
    const AoC::Vector2D m_goalPoseA;
    AoC::Grid2D<int> m_heatMap;
    const std::vector<std::string> m_data;
    uint64_t m_resultA;
    uint64_t m_resultB;
};

#endif //ADVENTOFCODE_DAY_H

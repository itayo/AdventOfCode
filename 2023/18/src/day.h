#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include "AoC/aoc.h"
#include <list>
#include "AoC/Grid2D.h"

class Day {
public:

    enum tDigInfo {
        Ground,
        ShouldDig,
        ShouldNotDig,
        Dug,
        Temp
    };
    struct tInput {
        AoC::Vector2D::tFacing dir;
        int64_t steps;
        std::string colorCode;
        struct tColorInfo {
            uint64_t r;
            uint64_t g;
            uint64_t b;
        } color;

    };

    Day(std::vector<std::string> data)
            : m_resultA(0), m_resultB(0), m_data(data), m_commands(data.size()) {
        std::regex rx("([ULRD]) ([0-9]*) \\((\\#([0-9a-f]{2})([0-9a-f]{2})([0-9a-f]{2}))\\)");
        uint64_t rightSteps,leftSteps,upSteps,downSteps;
        for (uint64_t i = 0; i < data.size(); ++i) {
            std::string line = data[i];
            auto parsed = aoc.ExtractMatches(rx, line);
            tInput &input = m_commands[i];
            input.steps = aoc.GetAllIntegersU64(parsed[1])[0];
            switch (parsed[0][0]) {
                case 'U':
                    input.dir = AoC::Vector2D::NORTH;
                     upSteps += input.steps;


                    break;
                case 'R':
                    input.dir = AoC::Vector2D::EAST;
                    rightSteps += input.steps;
                    break;
                case 'D':
                    input.dir = AoC::Vector2D::SOUTH;
                    downSteps += input.steps;
                    break;
                case 'L':
                    input.dir = AoC::Vector2D::WEST;
                    leftSteps += input.steps;
                    break;
            }
            input.colorCode = parsed[2];
            input.color.r = stoul(parsed[3], 0, 16);
            input.color.g = stoul(parsed[4], 0, 16);
            input.color.b = stoul(parsed[5], 0, 16);
        }


    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }


private:
    void Dig(std::vector<tInput> &m_inputsA);
    void TryFindInnerCircle(AoC::Grid2D<tDigInfo> &digInfo);

    std::vector<tInput> m_commands;
    const AoC::Grid2D<tDigInfo> m_digInfo;
    AoC::AoC aoc;
    const std::vector<std::string> m_data;
    uint64_t m_resultA;
    uint64_t m_resultB;
};

#endif //ADVENTOFCODE_DAY_H

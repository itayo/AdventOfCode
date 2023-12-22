#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include "AoC/aoc.h"
#include <list>
#include "AoC/Grid2D.h"
#include <unordered_set>
#include <unordered_map>

class Day {
public:

    struct tDirections {
        tDirections(int64_t x, int64_t y, AoC::Vector2D::tFacing p_facing) {
            pos.Override(x, y, p_facing);
            facing = p_facing;
        }

        AoC::Vector2D pos;
        AoC::Vector2D::tFacing facing;
    };

    Day(std::vector<std::string> data)
            : m_resultA(0), m_resultB(0), m_data(data), m_mapA(data.size(), data[0].size()),
              m_mapB(data.size(), data[0].size()) {
        for (int row = 0; row < data.size(); ++row) {
            for (int column = 0; column < data[row].size(); ++column) {
                char c = data[row][column];
                m_mapA.Set(row, column, c);
                if (c == '<' || c == '>' || c == 'v' || c == '^') {
                    m_mapB.Set(row, column, '.');
                } else {
                    m_mapB.Set(row, column, data[row][column]);
                }
            }
        }
        int64_t startX = 0;
        int64_t goalX = 0;
        if (!InitFindPos(data[0], startX, '.')) ExitIfReached();
        if (!InitFindPos(data[data.size() - 1], goalX, '.')) ExitIfReached();
        m_start.Override(startX, 0, AoC::Vector2D::SOUTH);
        m_goal.Override(goalX, data.size() - 1);
        m_dirs.emplace_back(0, 1, AoC::Vector2D::tFacing::SOUTH);
        m_dirs.emplace_back(0, -1, AoC::Vector2D::tFacing::NORTH);
        m_dirs.emplace_back(1, 0, AoC::Vector2D::tFacing::EAST);
        m_dirs.emplace_back(-1, 0, AoC::Vector2D::tFacing::WEST);

    }


    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }


private:
    std::vector<Day::tDirections> GetDirections(AoC::Vector2D pos, bool overrideHills);

    bool PositionValid(const AoC::Grid2D<char> &map, AoC::Vector2D pos, std::unordered_set<AoC::Vector2D> &visited,
                       bool overrideHills);

    void Walk(const AoC::Grid2D<char> &map, AoC::Vector2D currentPos, uint64_t steps,
              std::unordered_set<AoC::Vector2D> visited, std::unordered_map<AoC::Vector2D, uint64_t> &distances,
              bool overrideHills = false);

    bool InitFindPos(const std::string line, int64_t &value, char val = '.') {
        auto it = std::find_if(line.begin(), line.end(), [&val](char c) { return val == c; });
        if (it != line.end()) {
            value = std::distance(line.begin(), it);
            return true;
        }
        return false;
    };
    AoC::Grid2D<char> m_mapA;
    AoC::Grid2D<char> m_mapB;
    AoC::Vector2D m_start;
    AoC::Vector2D m_goal;
    std::vector<tDirections> m_dirs;
    AoC::AoC aoc;
    const std::vector<std::string> m_data;
    uint64_t m_resultA;
    uint64_t m_resultB;
};

#endif //ADVENTOFCODE_DAY_H

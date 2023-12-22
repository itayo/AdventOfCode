#include <iostream>
#include <queue>
#include <unordered_set>
#include "day.h"
#include <unordered_map>

template<>
struct std::hash<AoC::Vector2D> {
    size_t operator()(const AoC::Vector2D &vec) const noexcept {
        return std::hash<std::string>()(vec.Cord());
    }
};


void Day::PrepareData() {

}

std::vector<Day::tDirections> Day::GetDirections(AoC::Vector2D pos, bool overrideHills) {
    std::vector<tDirections> dirs;
    char c = m_mapA.Get(pos);
    if (c == '.' || overrideHills) return m_dirs;
    AoC::Vector2D::tFacing facing;
    switch (m_mapA.Get(pos)) {
        case '^':
            facing = AoC::Vector2D::NORTH;
            break;
        case '>':
            facing = AoC::Vector2D::EAST;
            break;
        case 'v':
            facing = AoC::Vector2D::SOUTH;
            break;
        case '<':
            facing = AoC::Vector2D::WEST;
            break;
    }

    auto it = std::find_if(m_dirs.begin(), m_dirs.end(), [&facing](tDirections dir) { return dir.facing == facing; });
    if (it == m_dirs.end()) ExitIfReached();
    return {*it};


}

bool
Day::PositionValid(const AoC::Grid2D<char> &map, AoC::Vector2D pos, std::unordered_set<AoC::Vector2D> &visited,
                   bool overrideHills) {
    if (!m_mapA.Exists(pos)) return false;
    if (visited.contains(pos)) return false;
    switch (m_mapA.Get(pos)) {
        case '^':
            return pos.IsFacing() == AoC::Vector2D::tFacing::NORTH || overrideHills;
        case '>':
            return pos.IsFacing() == AoC::Vector2D::tFacing::EAST || overrideHills;
        case 'v':
            return pos.IsFacing() == AoC::Vector2D::tFacing::SOUTH || overrideHills;
        case '<':
            return pos.IsFacing() == AoC::Vector2D::tFacing::WEST || overrideHills;
        case '.':
            return true;
    }
    //ExitIfReached();
    return false;
}


void Day::Walk(const AoC::Grid2D<char> &map, AoC::Vector2D currentPos, uint64_t steps,
               std::unordered_set<AoC::Vector2D> visited,
               std::unordered_map<AoC::Vector2D, uint64_t> &distances, bool overrideHills) {
    visited.insert(currentPos);
    if (steps < distances[currentPos]) {
        return;
    }
    distances[currentPos] = steps;


    auto dirs = GetDirections(currentPos, overrideHills);
    for (tDirections dir: dirs) {
        AoC::Vector2D n = currentPos + dir.pos;
        n.Override(dir.facing);
        if (PositionValid(map, n, visited, overrideHills)) {
            Walk(map, n, steps + 1, visited, distances,overrideHills);
        }
    }


}

void Day::RunA(bool secondData) {
    std::unordered_set<AoC::Vector2D, std::hash<AoC::Vector2D>> visited;
    std::unordered_map<AoC::Vector2D, uint64_t> distances;
    Walk(m_mapA, m_start, 0, visited, distances);
    m_resultA = distances.at(m_goal);

}

void Day::RunB() {
    std::unordered_set<AoC::Vector2D, std::hash<AoC::Vector2D>> visited;
    std::unordered_map<AoC::Vector2D, uint64_t> distances;
    Walk(m_mapB, m_start, 0, visited, distances, true);
    m_resultB = distances.at(m_goal);

}


void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include <vector>
#include "AoC/aoc.h"
#include <string>
#include <regex>
#include "AoC/Grid2D.h"
struct Entry
{
    uint64_t destination = 0;
    uint64_t source = 0;
    uint64_t lenght =0;
};
struct Map {
    std::vector<Entry> maps;
};

struct SeedRanges {
    SeedRanges(uint64_t a, uint64_t b) : from(a), range(b){}
    static bool compareByRangeAsc(const SeedRanges &a, const SeedRanges &b)
    {
        return a.range < b.range;
    }
    uint64_t from;
    uint64_t range;
};
class Day {

public:
    Day(std::vector<std::string> data)
            :m_resultA(0), m_resultB(0), m_data(data)
    {

    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }

private:
    AoC::AoC aoc;
    std::vector<std::string> m_data;
    std::vector<uint64_t> m_seedsA;
    std::vector<SeedRanges> m_seedsB;
    std::vector<Map> m_mapsA;

    uint64_t m_resultA;
    uint64_t m_resultB;
};

#endif //ADVENTOFCODE_DAY_H

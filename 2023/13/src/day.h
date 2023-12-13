#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include "AoC/aoc.h"
#include <list>
#include "AoC/Grid2D.h"

struct Maps {
    std::vector<std::string> origin;
    std::vector<std::string> transposed;

};

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
    void CreateMap(std::vector<std::string> cache);

    int TryFindMirrorLocation(std::vector<std::string> &map, bool findSmudge = false);

    bool IsMirrored(std::vector<std::string> &map, int index, bool findSmudge = false);

    void Runner(std::vector<Maps> &maps, uint64_t &result, bool findSmudge = false);
    std::pair<bool,bool> StringChecker(std::string left, std::string right);
    AoC::AoC aoc;
    const std::vector<std::string> m_data;
    std::vector<Maps> m_mapsA;
    std::vector<Maps> m_mapsB;
    uint64_t m_resultA;
    uint64_t m_resultB;
    int m_lr = 0;
};

#endif //ADVENTOFCODE_DAY_H

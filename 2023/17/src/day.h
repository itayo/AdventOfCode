#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include "AoC/aoc.h"
#include <list>
#include "AoC/Grid2D.h"

class Day {
    struct Lens {
        Lens(std::string lbl, uint64_t fc) : label(lbl), FocalLength(fc){}
        std::string label;
        uint64_t FocalLength;
    };

    struct Box {
        std::vector<Lens> lenses;
    };
public:

    Day(std::vector<std::string> data)
            : m_resultA(0), m_resultB(0), m_data(data), m_boxes(256) {

        for (auto line: m_data) {
            auto tmp = aoc.StringSplit(line, ',');
            m_sequences.insert(m_sequences.end(), tmp.begin(), tmp.end());
        }
    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }


private:
    void AddBox(std::string label, uint64_t focal) ;
    void RemoveBox(std::string label);
    uint64_t Hash(std::string hashString);
    std::vector<Box> m_boxes;
    AoC::AoC aoc;
    const std::vector<std::string> m_data;
    std::vector<std::string> m_sequences;
    uint64_t m_resultA;
    uint64_t m_resultB;
    int m_lr = 0;
};

#endif //ADVENTOFCODE_DAY_H

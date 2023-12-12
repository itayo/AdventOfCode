#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include "AoC/aoc.h"
#include <list>
#include "AoC/Grid2D.h"

struct tRow {
    tRow() {}

    tRow(std::string l, std::vector<uint64_t> b, std::string r) : line(l), broken(b), rx(r) {}

    std::string line;
    std::vector<uint64_t> broken;
    std::string rx;
};
class Day {
public:

    Day(std::vector<std::string> data)
            : m_resultA(0), m_resultB(0), m_data(data) {
        for (auto data: m_data) {
            std::string lineA = aoc.StringSplit(data, ' ')[0];
            auto brokenA = aoc.GetAllIntegersU64(aoc.StringSplit(data, ' ')[1]);

            m_rowsA.emplace_back(lineA + ".", brokenA, GenerateRegex(brokenA));
        }

        for (auto row: m_rowsA) {
            tRow newRow;
            auto line =  row.line.substr(0,  row.line.size()-1);
            newRow.line = line + "?" + line + "?" + line + "?" + line + "?" + row.line;
            for (int i = 0; i < 5; ++i)
                newRow.broken.insert(newRow.broken.end(), row.broken.begin(), row.broken.end());
            newRow.rx = GenerateRegex(newRow.broken);
            newRow.line += ".";
            m_rowsB.emplace_back(newRow);
        }
    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }



private:
    std::string GenerateRegex(std::vector<uint64_t> &groups);
    AoC::AoC aoc;
    const std::vector<std::string> m_data;
    std::vector<tRow> m_rowsA;
    std::vector<tRow> m_rowsB;
    uint64_t m_resultA;
    uint64_t m_resultB;
    int m_lr = 0;
};

#endif //ADVENTOFCODE_DAY_H

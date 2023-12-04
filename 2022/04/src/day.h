#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H
#include <vector>
#include <aoc.h>
#include <array>
struct tElf {
    tElf();
    tElf(int a, int b)
            :low(a), hi(b) { }
    int low;
    int hi;
};

struct tElfPairs {
    tElfPairs();
    tElfPairs(tElf a, tElf b)
            :m_a(a), m_b(b) { }
    tElf m_a;
    tElf m_b;
};

class Day {
public:
    Day(std::vector<std::string> data)
            :m_resultA(0), m_resultB(0), m_data(data)
    {
        for (auto pair: m_data) {
            auto elves = aoc.StringSplit(pair, ',');
            auto elfAValues = aoc.StringSplit(elves[0], '-');
            tElf elfA{std::stoi(elfAValues[0]), std::stoi(elfAValues[1])};
            auto elfBValues = aoc.StringSplit(elves[1], '-');
            tElf elfB{std::stoi(elfBValues[0]), std::stoi(elfBValues[1])};
            m_pair.push_back({elfA,elfB});
        }
    }
    void PrepareData();
    void RunA(bool secondData = false);
    void RunB();
    void Report();
    int ResultA() { return m_resultA; }
    int ResultB() { return m_resultB; }
private:
    AoC::AoC aoc;
    std::vector<std::string> m_data;
    std::vector<tElfPairs> m_pair;
    int m_resultA;
    int m_resultB;
};

#endif //ADVENTOFCODE_DAY_H

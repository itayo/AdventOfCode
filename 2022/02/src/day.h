#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H
#include <vector>
#include "AoC/aoc.h"

enum RPS {
    ROCK=1,
    PAPER=2,
    SCISSOR=3
};
struct tGame {
    RPS other;
    char me;
};
class Day {
public:
    Day(std::vector<std::string> data) : m_resultA(0), m_resultB(0), m_data(data) {}
    void PrepareData();
    void RunA(bool secondData = false);
    void RunB();
    void Report();
    int ResultA() { return m_resultA; }
    int ResultB() { return m_resultB; }
private:
    int DetermineWinner(RPS me, RPS other);
    RPS DetermineMyHand(RPS other, char outcome);
    AoC::AoC aoc;
    std::vector<std::string> m_data;
    std::vector<tGame> m_preparedData;
    int m_resultA;
    int m_resultB;
};


#endif //ADVENTOFCODE_DAY_H

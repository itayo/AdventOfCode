#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H
#include <vector>
#include "AoC/aoc.h"
#include <array>
#include <stack>
struct tCommand {
    int from;
    int to;
    int amount;
};
class Day {
public:
    Day(std::vector<std::string> data)
            :m_resultA(""), m_resultB(""), m_data(data)
    {
    }
    void PrepareData();
    void RunA(bool secondData = false);
    void RunB();
    void Report();
    std::string ResultA() { return m_resultA; }
    std::string ResultB() { return m_resultB; }
private:
    AoC::AoC aoc;
    std::vector<std::string> m_data;
    std::vector<tCommand> m_commands;
    std::vector<std::stack<char>> m_stacksA;
    std::vector<std::stack<char>> m_stacksB;
    std::string m_resultA;
    std::string m_resultB;
};

#endif //ADVENTOFCODE_DAY_H

#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H
#include <vector>
#include "AoC/aoc.h"

class tDraw {
public:
    tDraw(): red(0), green(0), blue(0){}
    tDraw(int r, int g, int b) : red(r),green(g),blue(b){}
    int red;
    int green;
    int blue;
};

class tGame {
public:
    int id;
    tDraw maximum;
    std::vector<tDraw> draws;
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
    std::string CleanString(std::string line);
    void PrepareGame(std::string line);
    AoC::AoC aoc;
    std::vector<std::string> m_data;
    std::vector<tGame> m_games;
    int m_resultA;
    int m_resultB;
};


#endif //ADVENTOFCODE_DAY_H

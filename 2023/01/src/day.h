//
// Created by snyg9u on 2023-11-17.
//

#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H


#include <vector>

class Day {
public:
    Day(std::vector<std::string> data);
    void runA(bool secondData=false);
    void runB();
    void report();
    int ResultA() {return m_resultA;}
    int ResultB() {return m_resultB;}
private:
    std::string wordToInt(std::string);
    int findFirstDigit(std::string);
    int commonCalc(std::string);
    std::vector<std::string> m_data;
    int m_resultA;
    int m_resultB;
};


#endif //ADVENTOFCODE_DAY_H

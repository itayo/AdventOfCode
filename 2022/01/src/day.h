//
// Created by snyg9u on 2023-11-17.
//

#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H


#include <vector>
struct elf {
    elf(int numbers, int calories) : m_number(numbers), m_calories(calories){}
    int m_number;
    int m_calories;
};

class Day {
public:
    Day(std::vector<std::string> data);
    void runA(bool secondData=false);
    void runB();
    void report();
    int ResultA() {return m_resultA;}
    int ResultB() {return m_resultB;}
private:
    std::vector<std::string> m_data;
    std::vector<elf> summarizeElfs();
    int m_resultA;
    int m_resultB;
};


#endif //ADVENTOFCODE_DAY_H

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
private:
    std::vector<int> m_data;
    std::vector<int> m_bData;
    int m_resultA;
    int m_resultB;
};


#endif //ADVENTOFCODE_DAY_H

#include <iostream>
#include "day.h"
#include <string>
#include <algorithm>

Day::Day(std::vector<std::string> data) : m_resultA(0), m_resultB(0), m_data(data) {
}



std::vector<elf> Day::summarizeElfs() {
    std::vector<elf> elfs;
    int elf=1;
    int calories=0;
    for(auto line: m_data)
    {

        if(line == "") {
            elfs.push_back({elf,calories});
            elf += 1;
            calories = 0;
        } else {
            calories += std::stoi(line);
        }
    }
    elfs.push_back({elf,calories});
    std::sort(elfs.begin(),elfs.end(), [](struct elf &a, struct elf &b){ return a.m_calories >b.m_calories; });
    return elfs;
}
void Day::runA(bool secondData) {
 auto elfs = Day::summarizeElfs();
 m_resultA =elfs[0].m_calories;

}

void Day::runB() {
    auto elfs = Day::summarizeElfs();
    m_resultB =elfs[0].m_calories + elfs[1].m_calories + elfs[2].m_calories;
}

void Day::report() {
    std::cout << "2021-01-1: " << m_resultA << std::endl;
    std::cout << "2021-01-2: " << m_resultB;
}
#include "day.h"
#include <algorithm>
#include <iostream>

void Day::PrepareData() {
    for (std::string line: m_data) {
        m_formattedData.push_back({line.substr(0, line.length() / 2), line.substr(line.length() / 2)});
    }
}


void Day::RunA(bool secondData) {
    for (auto rucksack: m_formattedData) {
        std::vector<char> items;
        for (char itemLeft: rucksack[0]) {
            for (char itemRight: rucksack[1]) {
                if (itemLeft == itemRight) {
                    items.push_back(itemLeft);
                }
            }
        }
        auto it = unique(items.begin(), items.end());
        items.resize(distance(items.begin(), it));
        for(auto item: items) {
            if(std::islower(item)) {
                m_resultA += item - 96;
            } else {
                m_resultA += item - 63 + 25;
            }
        }
    }

}

void Day::RunB() {

}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
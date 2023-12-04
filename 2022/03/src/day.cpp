#include "day.h"
#include <algorithm>
#include <iostream>

void Day::PrepareData()
{
    for (std::string line: m_data) {
        m_formattedDataA.push_back({line.substr(0, line.length()/2), line.substr(line.length()/2)});
    }
    for (int i = 0; i<m_data.size(); i += 3) {
        m_formattedDataB.push_back({m_data[i], m_data[i+1], m_data[i+2]});
    }
}

void Day::RunA(bool secondData)
{
    for (auto rucksack: m_formattedDataA) {
        std::vector<char> items;
        for (char itemLeft: rucksack[0]) {
            for (char itemRight: rucksack[1]) {
                if (itemLeft==itemRight) {
                    items.push_back(itemLeft);
                }
            }
        }
        auto it = unique(items.begin(), items.end());
        items.resize(distance(items.begin(), it));
        for (auto item: items) {
            if (std::islower(item)) {
                m_resultA += item-96;
            }
            else {
                m_resultA += item-63+25;
            }
        }
    }
}

void Day::RunB()
{
    for (std::array<std::string, 3> rucksacks: m_formattedDataB) {
        std::vector<char> items;
        for (char item: rucksacks[0]) {
            if (rucksacks[1].find(item)!=std::string::npos && rucksacks[2].find(item)!=std::string::npos)
                items.push_back(item);
        }
        auto it = unique(items.begin(), items.end());
        items.resize(distance(items.begin(), it));
        for (auto item: items) {
            if (std::islower(item)) {
                m_resultB += item-96;
            }
            else {
                m_resultB += item-63+25;
            }
        }

    }
}

void Day::Report()
{
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
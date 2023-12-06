#include "day.h"
#include <algorithm>
#include <iostream>

void Day::PrepareData()
{

}

void Day::RunA(bool secondData)
{
    for (auto elves: m_pair) {
        std::vector<int> shifts;
        if ((elves.m_a.low<=elves.m_b.low && elves.m_a.hi>=elves.m_b.hi)
                || (elves.m_a.low>=elves.m_b.low && elves.m_a.hi<=elves.m_b.hi))
            m_resultA++;
    }

}

void Day::RunB()
{
    for (auto elves: m_pair) {
        std::vector<int> shifts;
        if ((elves.m_a.low <= elves.m_b.hi) && elves.m_b.low <= elves.m_a.hi)
            m_resultB++;
    }

}

void Day::Report()
{
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
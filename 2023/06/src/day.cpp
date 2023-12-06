#include <iostream>
#include "day.h"

void Day::PrepareData()
{

}

uint64_t Day::CalculateRace(const tRace& race)
{
    for (uint64_t hold = 1; hold<race.time; ++hold) {
        if (hold*(race.time-hold)>race.distance) {
            return race.time-(2*hold)+1;
        }
    }
    return 0;
}

uint64_t Day::CalculateRaces(const std::vector<tRace>& races)
{
    std::vector<uint64_t> wins;
    uint64_t result = 1;
    for (tRace race: races) {
        wins.push_back(CalculateRace(race));
    }
    if (std::find(wins.begin(), wins.end(), 0)!=wins.end()) {
        return 0;
    }
    if (wins.size()==1) {
        return wins[0];
    }
    for (auto win: wins) {
        result *= win;
    }
    return result;
}

void Day::RunA(bool secondData)
{
    m_resultA = CalculateRaces(m_racesA);
}

void Day::RunB()
{
    m_resultB = CalculateRace(m_racesB[0]);
}

void Day::Report()
{
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
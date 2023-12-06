#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include <vector>
#include <aoc.h>
#include <string>
#include <regex>
#include "Grid2D.h"
struct tRace {
    tRace(){}
    tRace(uint32_t t, uint32_t d) :time(t), distance(d){}
    uint64_t time=0;
    uint64_t distance=0;
};

class Day {

public:
    Day(std::vector<std::string> data)
            :m_resultA(0), m_resultB(0), m_data(data)
    {
        auto times = aoc.GetAllIntegersU64(m_data[0]);
        auto distances = aoc.GetAllIntegersU64(m_data[1]);
        if(times.size() != distances.size()) {
            throw std::invalid_argument("size for time and distances doesnt match");
        }

        for(size_t i=0; i< times.size();++i) {
            m_racesA.emplace_back(times[i],distances[i]);
        }
        aoc.StringReplace(m_data[0],{{" ",""}});
        aoc.StringReplace(m_data[1],{{" ",""}});

        for(auto &line: m_data) {
            while(line.find(" ") != std::string::npos)
            {
                aoc.StringReplace(line, {{" ",""}});
            }
        }

        auto time = aoc.GetAllIntegersU64(m_data[0]);
        auto distance = aoc.GetAllIntegersU64(m_data[1]);
        if(times.size() != distances.size() && times.size() != 1) {
            throw std::invalid_argument("size for time and distances doesnt match or are not 1 for part B");
        }
        tRace race;
        race.time = time[0];
        race.distance = distance[0];
        m_racesB.emplace_back(race);
    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }

private:
    uint64_t CalculateRaces(const std::vector<tRace> & races);
    uint64_t CalculateRace(const tRace& race);
    AoC::AoC aoc;
    std::vector<std::string> m_data;
    std::vector<tRace> m_racesA;
    std::vector<tRace> m_racesB;
    uint64_t m_resultA;
    uint64_t m_resultB;
};

#endif //ADVENTOFCODE_DAY_H

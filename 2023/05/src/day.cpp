#include <iostream>
#include <thread>
#include <future>
#include "day.h"

void Day::PrepareData()
{
    auto data = m_data;

    //Extract seeds;
    {
        auto seeds = aoc.GetAllIntegersU64(data[0]);
        for (auto seed: seeds) {
            m_seedsA.push_back(seed);
        }
        for (uint64_t i = 0; i<=seeds.size()/2; i += 2) {
            SeedRanges range(seeds[i], seeds[i+1]);
            m_seedsB.emplace_back(range);
        }
        data.erase(data.begin());
    }
    //Extract Maps to a unordered map
    {

        while (data.size()!=0) {
            data.erase(data.begin());
            //Get from to
            {
                if (!aoc.StringEndsWith(data[0], "map:")) {
                    throw std::invalid_argument(data[0]);
                }
                data.erase(data.begin());
            }
            //Parse out conversion
            {
                Map currMap;
                while (data[0]!="" && !data.empty()) {

                    std::vector<uint64_t> placements = aoc.GetAllIntegersU64(data[0]);
                    Entry entry;
                    entry.source = placements[1];
                    entry.destination = placements[0];
                    entry.lenght = placements[2];
                    currMap.maps.emplace_back(entry);
                    data.erase(data.begin());
                }
                m_maps.emplace_back(currMap);
            }
        }
    }
}

uint64_t Traverse(uint64_t seed, std::vector<Map> maps)
{
    uint64_t location = seed;
    std::vector<uint64_t> sequence;
    for (const Map map: maps) {
        sequence.push_back(location);
        for (const Entry entry: map.maps) {

            if (entry.source<=location && location<entry.source+entry.lenght) {
                location = entry.destination+(location-entry.source);
                break;
            }
        }
    }
    sequence.push_back(location);
    return location;
}

void TraverseRange(std::promise<uint64_t>&& result, SeedRanges range, std::vector<Map> map, size_t pos)
{
    uint64_t calcRes = std::numeric_limits<uint64_t>::max();
    for (uint64_t i = range.from; i<range.from+range.range; ++i) {
          uint64_t currRes = Traverse(i, map);
        calcRes = std::min(currRes, calcRes);
    }
    result.set_value(calcRes);

}

void Day::RunA(bool secondData)
{
    m_resultA = std::numeric_limits<uint64_t>::max();
    for (uint64_t location: m_seedsA) {

        m_resultA = std::min(Traverse(location, m_maps), m_resultA);
    }
    return;
}

void Day::RunB()
{
    size_t threadCount = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    m_resultB = std::numeric_limits<uint64_t>::max();
    while (m_seedsB.size()<=threadCount) {
        std::sort(m_seedsB.begin(), m_seedsB.end(), SeedRanges::compareByRangeAsc);
        SeedRanges tmp = m_seedsB.back();
        m_seedsB.pop_back();
        uint64_t half = tmp.range/2;
        m_seedsB.emplace_back(tmp.from, half);
        m_seedsB.emplace_back(tmp.from+half, tmp.range-half);
    }
    std::sort(m_seedsB.begin(), m_seedsB.end(), SeedRanges::compareByRangeAsc);
    std::vector<std::promise<uint64_t>> promieses(m_seedsB.size());
    std::vector<std::future<uint64_t>> results(m_seedsB.size());
    for (size_t pos = 0; pos<m_seedsB.size(); ++pos) {
        results[pos] = promieses[pos].get_future();
        threads.emplace_back(&TraverseRange, std::move(promieses[pos]), m_seedsB[pos], m_maps, pos);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    auto threadC = threads.size();
    std::for_each(threads.begin(), threads.end(), [&threadC](std::thread& t) {
        t.join();
        threadC--;
    });
    for (auto& result: results) {
        m_resultB = std::min(m_resultB, result.get());
    }
}

void Day::Report()
{
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
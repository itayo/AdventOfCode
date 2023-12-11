#include <iostream>
#include <numeric>
#include "day.h"

void Day::PrepareData() {
    for (int i = 0; i < m_data.size(); ++i) {
        if (std::all_of(m_data[i].begin(), m_data[i].end(), [](char c) { return c == '.'; })) {
            m_expansionY.emplace_back(i);
        }
    }
    for (int column = 0; column < m_data[0].size(); ++column) {
        int inserts = 1;
        if (std::all_of(m_data.begin(), m_data.end(),
                        [&column](std::string c) { return c[column] == '.'; })) {
            m_expansionX.emplace_back(column);
        }
    }
    m_map.Reset(m_data.size(), m_data[0].size());
    for (int row = 0; row < m_data.size(); ++row) {
        for (int col = 0; col < m_data[0].size(); ++col) {
            m_map.Set(row, col, m_data[row][col]);
        }
    }
}

void Day::RunA(bool secondData) {
    std::vector<AoC::Vector2D> locations = m_map.FindAllLocationsOf('#');
    std::vector<Vector2DPair> pairs;
    for (int i = 0; i < locations.size() - 1; ++i) {
        for (int j = i + 1; j < locations.size(); ++j) {
            pairs.emplace_back(locations[i], locations[j], 0);
        }
    }
    Calculate(pairs, 2);
    for (auto loc: pairs) {
        m_resultA += loc.steps;
    }
}

void Day::Calculate(std::vector<Vector2DPair> &p_pairs, uint64_t expansion = 2) {
    for (auto &pair: p_pairs) {
        AoC::Vector2D &start = pair.start;
        AoC::Vector2D &stop = pair.stop;
        uint64_t ex = std::count_if(m_expansionX.begin(), m_expansionX.end(), [&start, &stop](int expansion) {
            return IsInBounds(expansion, start.X(), stop.X());
        });
        uint64_t ey = std::count_if(m_expansionY.begin(), m_expansionY.end(), [&start, &stop](int expansion) {
            return IsInBounds(expansion, start.Y(), stop.Y());
        });
        uint64_t x = std::abs(start.X() - stop.X()) - ex;
        uint64_t y = std::abs(start.Y() - stop.Y()) - ey;
        pair.steps = x + y + ((ex + ey) * expansion);

    }


}

void Day::RunB() {
    std::vector<AoC::Vector2D> locations = m_map.FindAllLocationsOf('#');
    std::vector<Vector2DPair> pairs;
    for (int i = 0; i < locations.size() - 1; ++i) {
        for (int j = i + 1; j < locations.size(); ++j) {
            pairs.emplace_back(locations[i], locations[j], 0);
        }
    }
    Calculate(pairs, 1'000'000);
    for (auto loc: pairs) {
        m_resultB += loc.steps;
    }
}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
#include <iostream>
#include <numeric>
#include "day.h"


int Day::CalculateSequence(const std::vector<int> &sequence, bool backwards) {
    std::vector<int> difference;
    for (size_t i = 1; i < sequence.size(); i++) {
        difference.push_back(sequence[i] - sequence[i - 1]);
    }
    int zero = 0;
    if (std::all_of(difference.begin(), difference.end(), [&zero](int v) { return v == zero; })) return 0;

    const int n = backwards ? difference[0] : difference[difference.size() - 1];
    return n + ((backwards ? -1 : 1) * CalculateSequence(difference,backwards));
}

void Day::PrepareData() {
    for (auto const &data: m_data) {
        auto line = aoc.StringSplit(data, ' ');
        std::vector<int> row;
        for (auto number: line) {
            row.emplace_back(std::stoi(number));
        }
        m_sequence.emplace_back(row);
    }
}

void Day::RunA(bool secondData) {
    for (auto const &sequence: m_sequence) {
        m_resultA += sequence[sequence.size() - 1] + CalculateSequence(sequence);
    }
}

void Day::RunB() {
    for (auto const &sequence: m_sequence) {
        m_resultB += sequence[0] - CalculateSequence(sequence, true);
    }
}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
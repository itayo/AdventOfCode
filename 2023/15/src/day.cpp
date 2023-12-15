#include <iostream>
#include "day.h"

void Day::PrepareData() {

}

uint64_t Day::Hash(std::string hashString) {
    uint64_t hash = 0;
    for (unsigned char c: hashString) {
        hash += c;
        hash *= 17;
        hash %= 256;
    }
    return hash;
}

void Day::AddBox(std::string label, uint64_t focal) {
    auto hash = Hash(label);
    auto it = std::find_if(m_boxes[hash].lenses.begin(), m_boxes[hash].lenses.end(),
                           [&label](Lens lens) { return lens.label == label; });
    if (it != m_boxes[hash].lenses.end()) {
        it->FocalLength = focal;
        return;
    }
    m_boxes[hash].lenses.emplace_back(label, focal);

}

void Day::RemoveBox(std::string label) {
    auto hash = Hash(label);
    auto it = std::find_if(m_boxes[hash].lenses.begin(), m_boxes[hash].lenses.end(),
                           [&label](Lens lens) { return lens.label == label; });
    if (it == m_boxes[hash].lenses.end()) return;
    m_boxes[hash].lenses.erase(it);
}


void Day::RunA(bool secondData) {
    for (auto sequence: m_sequences) {
        m_resultA += Hash(sequence);
    }

}


void Day::RunB() {
    for (auto sequence: m_sequences) {
        if (sequence.find('=') != std::string::npos) {
            std::string label = aoc.StringSplit(sequence, '=')[0];
            uint64_t focal = aoc.GetAllIntegersU64(aoc.StringSplit(sequence, '=')[1])[0];
            AddBox(label, focal);
        } else if (sequence.find('-') != std::string::npos) {
            std::string label = aoc.StringSplit(sequence, '-')[0];
            RemoveBox(label);

        } else ExitIfReached();
    }

    for (int i = 0; i < m_boxes.size(); ++i) {
        for (int j = 0; j < m_boxes[i].lenses.size(); ++j) {
            m_resultB += (i + 1) * (j + 1) * m_boxes[i].lenses[j].FocalLength;
        }

    }

}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
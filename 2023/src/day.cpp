#include <iostream>
#include <fileread.h>
#include "day.h"

Day::Day(std::vector<std::string> data) : m_resultA(0), m_resultB(0) {
    for (std::string line: data) {
        m_data.push_back(stoi(line));
    }
}

void Day::runA(bool secondData) {
    std::vector<int> data = secondData ? m_bData : m_data;
    int result = 0;
    int current = data[0];
    int next;
    for (size_t i = 0; i < data.size(); i++) {
        next = data[i];
        if (current < next) {
            ++result;
        }
        current = next;
    }
    if (secondData) {
        m_resultB = result;
    } else {
        m_resultA = result;
    }
}

void Day::runB() {
    int current = 0;
    std::vector<int> results;
    for (int i = 0; i < m_data.size() - 2; i++) {
        int values = 0;
        current = 0;

        for (int j = i; j < i + 3 && j < m_data.size(); j++) {
            if (j > 0 && j < m_data.size()) {
                ++values;
                current += m_data[j];
            }
        }
        if (values != 0) {
            m_bData.push_back(current);
        }
    }
    runA(true);
}

void Day::report() {
    std::cout << "2021-01-1: " << m_resultA << std::endl;
    std::cout << "2021-01-2: " << m_resultB;
}
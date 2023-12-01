#include <iostream>
#include "day.h"
#include <bitset>
#include "dayinfo.h"
#include <algorithm>
#include<string>
#include <math.h>

struct Results {
    std::string string;
    unsigned int number;
};

unsigned int string2int(std::string str) {
    std::reverse(str.begin(),str.end());
    unsigned int result=0;
    for(size_t i=0; i < str.length(); i++)
    {
        if(str[i] == '1') { result += std::pow(2, i); }
    }
    return result;
}

Day::Day(std::vector<std::string> data) : m_data(data), m_resultA(0), m_resultB(0) {
}

void Day::runA() {
    for(std::string line : m_data) {
        for (size_t i = 0; i < line.length(); i++) {
            while (m_bitState.size() < line.length()) {
                m_bitState.push_back(0);
            }
            m_bitState[i] = line.at(i) == '1' ? 1 : -1;
        }
    }
    Results gamma, epsilon;
    for(int val : m_bitState) {
        gamma.string.append(val < 0 ? "1":"0");
        epsilon.string.append(val >= 0 ? "1":"0");
    }
    gamma.number = string2int(gamma.string);
    epsilon.number = string2int(epsilon.string);
    m_resultA = static_cast<int>(epsilon.number * gamma.number);
}

void Day::runB() {

}

void Day::report() {
    std::cout << DAY_NAME << ": " << ((m_resultA == 0) ? "N/A" : std::to_string(m_resultA)) << std::endl;
    std::cout << DAY_NAME << ": " <<  ((m_resultB == 0) ? "N/A" : std::to_string(m_resultB));
}
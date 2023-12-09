#include "day.h"
#include <iostream>

void Day::PrepareData() {

}

void Day::Run(int &result, int size) {
  result = size - 1;
  while (true) {
    result++;
    std::string str = m_data[0].substr(result - size, size);
    std::sort(str.begin(), str.end());
    bool allUnique = true;
    for (int i = 0; i < str.size() - 1 && allUnique; i++) {
      allUnique = allUnique && str[i] != str[i + 1];
      if (!allUnique) { continue; }
    }
    if (allUnique) { return; }
  }
}

void Day::RunA(bool secondData) {
  Run(m_resultA, 4);
}

void Day::RunB() {
  Run(m_resultB, 14);
}

void Day::Report() {
  std::cout << "Part A: " << m_resultA << std::endl;
  std::cout << "Part B: " << m_resultB;
}
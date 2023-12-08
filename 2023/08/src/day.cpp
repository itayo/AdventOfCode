#include <iostream>
#include <numeric>
#include "day.h"

void Day::PrepareData() {
  std::string line = m_data[0];
  for (char c : line) {
    switch (c) {
      case 'L':m_dir.push_back(Dir::LEFT);
        break;
      case 'R':m_dir.push_back(Dir::RIGHT);
        break;
    }
  }
  std::regex rx("^([A-Z1-9]{3}) = \\(([A-Z1-9]{3}), ([A-Z1-9]{3})\\)$");
  for (size_t i = 2; i < m_data.size(); ++i) {
    auto matches = aoc.ExtractMatches(rx, m_data[i]);
    m_map[matches[0]] = {matches[1], matches[2]};
    if (aoc.StringEndsWith(matches[0], "A")) {
      m_locationsB.push_back(matches[0]);
    }
  }
}

void Day::Move(std::string &string, bool increase) {
  if (m_lr == m_dir.size()) { m_lr = 0; }
  string = m_map[string][m_dir[m_lr]];
  if (increase) {
    m_lr++;
    if (m_lr == m_dir.size()) { m_lr = 0; }
  }
}
void Day::RunA(bool secondData) {
  std::string string = "AAA";
  while (string != "ZZZ") {
    Move(string);
    m_resultA++;
  }
}

void Day::RunB() {
  bool done = false;
  std::vector<int> steps(m_locationsB.size(), 0);
  while (!done) {
    m_resultB++;
    for (size_t pos = 0; pos < m_locationsB.size(); ++pos) {
      if (steps[pos] == 0) {
        Move(m_locationsB[pos], false);
        steps[pos] = aoc.StringEndsWith(m_locationsB[pos], "Z") ? m_resultB : 0;
      }
    }
    m_lr++;
    if (m_lr == m_dir.size()) { m_lr == 0; }
    bool runDone = true;
    for (auto &location : m_locationsB) {

      runDone = runDone && aoc.StringEndsWith(location, "Z");
    }
    done = runDone;

  }
  m_resultB = 1;
  for (int i = 0; i < steps.size(); i++) {
    m_resultB = std::lcm(m_resultB, steps[i]);
  }
}

void Day::Report() {
  std::cout << "Part A: " << m_resultA << std::endl;
  std::cout << "Part B: " << m_resultB;
}
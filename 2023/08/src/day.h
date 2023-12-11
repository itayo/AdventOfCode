#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H
#include "AoC/aoc.h"
#include <list>
#include "AoC/Grid2D.h"
enum Dir {
  LEFT = 0,
  RIGHT = 1
};

struct LRObject {
  LRObject(std::string l, std::string r) : Left(l), Right(r) {}
  const std::string Left;
  const std::string Right;
};

class Day {
 public:
  Day(std::vector<std::string> data)
      : m_resultA(0), m_resultB(0), m_data(data) {
  }

  void PrepareData();

  void RunA(bool secondData = false);

  void RunB();

  void Report();

  uint64_t ResultA() { return m_resultA; }

  uint64_t ResultB() { return m_resultB; }

 private:
  void Move(std::string &,bool increase=true);
  AoC::AoC aoc;
  std::unordered_map<std::string,std::vector<std::string>> m_map;
  std::vector<std::string> m_locationsB;
  const std::vector<std::string> m_data;
  std::vector<Dir> m_dir;
  uint64_t m_resultA;
  uint64_t m_resultB;
  int m_lr=0;
};

#endif //ADVENTOFCODE_DAY_H

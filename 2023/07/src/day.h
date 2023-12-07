#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H
#include <aoc.h>
#include "Grid2D.h"
enum HandRank {
  HiCard = 1,
  OnePair = 2,
  TwoPair = 3,
  ThreeOfAKind = 4,
  FullHouse = 5,
  FourOfAKind = 6,
  FiveOfAKind = 7
};
class Day {

  struct Hand {
    Hand(std::string h, uint64_t v, HandRank r, std::vector<int> ranker) : hand(h), value(v), rank(r), rankers(ranker) {}
    bool compareByRank(const Hand &a, const Hand &b) { return a.rank < b.rank; }
    bool compareByValue(const Hand &a, const Hand &b) { return a.value < b.value; }
    bool operator<(const Hand &rhs) const {
      if(rank == rhs.rank) {
        for(int i=0;i< rankers.size(); ++i) {
          if(rankers[i] == rhs.rankers[i]) {
            continue;
          }
          return rankers[i] < rhs.rankers[i];
        }
      }
      return rank < rhs.rank;
    }
    std::string hand;
    uint64_t value;
    HandRank rank;
    std::vector<int> rankers;
  };

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
  HandRank RankHandA(const std::string &p_hand, std::vector<int> &p_ranker);
  HandRank RankHandB(const std::string &p_hand, std::vector<int> &p_ranker);
  int CardToIntA(char card);
  int CardToIntB(char card);
  AoC::AoC aoc;
  std::vector<std::string> m_data;
  std::vector<Hand> m_handsA;
  std::vector<Hand> m_handsB;
  uint64_t m_resultA;
  uint64_t m_resultB;
};

#endif //ADVENTOFCODE_DAY_H

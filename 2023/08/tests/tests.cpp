#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"

TEST(day202308, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 6);
}
TEST(day202308, PartTwo) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
  Day day{input};
  day.PrepareData();
  day.RunB();
  EXPECT_EQ(day.ResultB(), 6);
}


TEST(day202308, MyRealData) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("../input.txt");
  Day day{input};
  day.PrepareData();
  day.RunA();
  day.RunB();
  EXPECT_EQ(day.ResultA(), 12737);
  EXPECT_EQ(day.ResultB(), 9064949303801);
}
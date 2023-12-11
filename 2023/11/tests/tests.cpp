#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"

TEST(day202311, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 374);
}
TEST(day202311, PartTwo) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
  Day day{input};
  day.PrepareData();
  day.RunB();
  EXPECT_EQ(day.ResultB(), 82000210);
}


TEST(day202311, MyRealData) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("../input.txt");
  Day day{input};
  day.PrepareData();
  day.RunA();
  day.RunB();
  EXPECT_EQ(day.ResultA(), 9522407);
  EXPECT_EQ(day.ResultB(), 544723432977);
}
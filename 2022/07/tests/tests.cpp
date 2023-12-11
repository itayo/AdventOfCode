#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"

TEST(day202207, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 95437);
}
TEST(day202207, PartTwo) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
  Day day{input};
  day.PrepareData();
  day.RunB();
  EXPECT_EQ(day.ResultB(), 24933642);
}


TEST(day202207, MyRealData) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("../input.txt");
  Day day{input};
  day.PrepareData();
  day.RunA();
  day.RunB();
  EXPECT_EQ(day.ResultA(), 1086293);
  EXPECT_EQ(day.ResultB(), 366028);
}

#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"

TEST(day202301, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.runA();
    EXPECT_EQ(day.ResultA(), 142);
}
TEST(day202301, PartTwo) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
    Day day{input};
    day.runB();
    EXPECT_EQ(day.ResultB(), 281);
}

TEST(day202301, MyRealData) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("../input.txt");
  Day day{input};
  day.runA();
  day.runB();
  EXPECT_EQ(day.ResultA(), 54632);
  EXPECT_EQ(day.ResultB(), 54019);
}
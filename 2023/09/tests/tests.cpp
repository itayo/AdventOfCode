#include <gtest/gtest.h>
#include <day.h>
#include <aoc.h>

TEST(day202309, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 114);
}
TEST(day202309, PartTwo) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
  Day day{input};
  day.PrepareData();
  day.RunB();
  EXPECT_EQ(day.ResultB(), 2);
}


TEST(day202309, MyRealData) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("../input.txt");
  Day day{input};
  day.PrepareData();
  day.RunA();
  day.RunB();
  EXPECT_EQ(day.ResultA(), 1974913025);
  EXPECT_EQ(day.ResultB(), 884);
}
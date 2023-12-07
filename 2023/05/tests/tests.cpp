#include <gtest/gtest.h>
#include <day.h>
#include <aoc.h>

TEST(day202305, PartOne) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
  Day day{input};
  day.PrepareData();
  day.RunA();
  EXPECT_EQ(day.ResultA(), 35);
}
TEST(day202305, PartTwo) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
  Day day{input};
  day.PrepareData();
  day.RunB();
  EXPECT_EQ(day.ResultB(), 46);
}

TEST(day202305, MyRealData) {

  GTEST_SKIP() << "Skipped due to execution time";
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("../input.txt");
  Day day{input};
  day.PrepareData();
  day.RunA();
  day.RunB();
  EXPECT_EQ(day.ResultA(), 382895070);
  EXPECT_EQ(day.ResultB(), 17729182);
}
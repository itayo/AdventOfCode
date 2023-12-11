#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"
struct tTestCase {
  tTestCase(int e, std::vector<std::string> d) : expected(e), testdata(d) {}
  const int expected;
  const std::vector<std::string> testdata;
};

TEST(day202206, PartOne) {
  std::vector<tTestCase> testCases;
  testCases.emplace_back(5, std::vector<std::string>{"bvwbjplbgvbhsrlpgdmjqwftvncz"});
  testCases.emplace_back(6, std::vector<std::string>{"nppdvjthqldpwncqszvftbrmjlhg"});
  testCases.emplace_back(10, std::vector<std::string>{"nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg"});
  testCases.emplace_back(11, std::vector<std::string>{"zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw"});
  for(auto testCase: testCases) {
    AoC::AoC aoc;
    Day day{testCase.testdata};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), testCase.expected);
  }
}
TEST(day202206, PartTwo) {
  std::vector<tTestCase> testCases;
  testCases.emplace_back(19, std::vector<std::string>{"mjqjpqmgbljsphdztnvjfqwrcgsmlb"});
  testCases.emplace_back(23, std::vector<std::string>{"bvwbjplbgvbhsrlpgdmjqwftvncz"});
  testCases.emplace_back(23, std::vector<std::string>{"nppdvjthqldpwncqszvftbrmjlhg"});
  testCases.emplace_back(29, std::vector<std::string>{"nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg"});
  testCases.emplace_back(26, std::vector<std::string>{"zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw"});
  for(auto testCase: testCases) {
    AoC::AoC aoc;
    Day day{testCase.testdata};
    day.PrepareData();
    day.RunB();
    EXPECT_EQ(day.ResultB(), testCase.expected);
  }
}

TEST(day202206, MyRealData) {
  AoC::AoC aoc;
  std::vector<std::string> input = aoc.ReadFile("../input.txt");
  Day day{input};
  day.PrepareData();
  day.RunA();
  day.RunB();
  EXPECT_EQ(day.ResultA(), 1361);
  EXPECT_EQ(day.ResultB(), 3263);
}
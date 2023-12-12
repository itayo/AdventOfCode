#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"

TEST(day202312, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 21);
}
TEST(day202312, PartTwo) {
    GTEST_SKIP() << "execution time to long. but passes"
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
    Day day{input};
    day.PrepareData();
    day.RunB();
    EXPECT_EQ(day.ResultB(), 525152);
}


TEST(day202312, MyRealData) {
    GTEST_SKIP() << "execution time to long. got no answer"
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("../input.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    day.RunB();
    EXPECT_EQ(day.ResultA(), 7490);
    EXPECT_EQ(day.ResultB(), 544723432977);
}

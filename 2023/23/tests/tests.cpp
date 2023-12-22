#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"

TEST(day202323, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 94);
}
TEST(day202323, PartTwo) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
    Day day{input};
    day.PrepareData();
    day.RunB();
    EXPECT_EQ(day.ResultB(), 154);
}


TEST(day202323, MyRealData) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("../input.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 2194);
    day.RunB();
    EXPECT_EQ(day.ResultB(), 6410);
}

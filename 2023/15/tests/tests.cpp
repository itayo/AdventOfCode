#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"

TEST(day202315, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 1320);
}
TEST(day202315, PartTwo) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
    Day day{input};
    day.PrepareData();
    day.RunB();
    EXPECT_EQ(day.ResultB(), 145);
}


TEST(day202315, MyRealData) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("../input.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 510792);
    day.RunB();
    EXPECT_EQ(day.ResultB(), 269410);
}

#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"

TEST(day202317, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 1320);
}
TEST(day202317, PartTwo) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
    Day day{input};
    day.PrepareData();
    day.RunB();
    EXPECT_EQ(day.ResultB(), 145);
}


TEST(day202317, MyRealData) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("../input.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 855);
    day.RunB();
    EXPECT_EQ(day.ResultB(), 980);
}

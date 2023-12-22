#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"

TEST(day202319, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 19114);
}
TEST(day202319, PartTwo) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
    Day day{input};
    day.PrepareData();
    day.RunB();
    EXPECT_EQ(day.ResultB(), 167409079868000);
}


TEST(day202319, MyRealData) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("../input.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 476889);
    day.RunB();
    EXPECT_EQ(day.ResultB(), 132380153677887);
}

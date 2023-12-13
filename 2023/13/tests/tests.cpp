#include <gtest/gtest.h>
#include <day.h>
#include "AoC/aoc.h"

TEST(day202313, PartOne) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput1.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    EXPECT_EQ(day.ResultA(), 405);
}
TEST(day202313, PartTwo) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("testInput2.txt");
    Day day{input};
    day.PrepareData();
    day.RunB();
    EXPECT_EQ(day.ResultB(), 400);
}


TEST(day202313, MyRealData) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("../input.txt");
    Day day{input};
    day.PrepareData();
    day.RunA();
    day.RunB();
    EXPECT_EQ(day.ResultA(), 27300);
    EXPECT_EQ(day.ResultB(), 29276);
}

#include <gtest/gtest.h>
#include <day.h>
#include <fileread.h>

TEST(day202301, PartOne) {
    std::vector<std::string> input = aoc::ReadFile("testInput1.txt");
    Day day{input};
    day.runA();
    EXPECT_EQ(day.ResultA(), 142);
}
TEST(day202301, PartTwo) {
    std::vector<std::string> input = aoc::ReadFile("testInput2.txt");
    Day day{input};
    day.runB();
    EXPECT_EQ(day.ResultB(), 281);
}
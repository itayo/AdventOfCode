#include "AoC/aoc.h"
#include <string>
#include <vector>
#include "day.h"


int main(int argc, char *argv[]) {
    AoC::AoC aoc;
    std::vector<std::string> input = aoc.ReadFile("input.txt");
    Day day{input};
    day.runA();
    day.runB();
    day.report();
}
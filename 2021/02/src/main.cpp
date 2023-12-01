#include "fileread.h"
#include <string>
#include <vector>
#include "day.h"


int main(int argc, char *argv[]) {
    std::vector<std::string> input = aoc::ReadFile("input.txt");
    Day day{input};
    day.runA();
    day.runB();
    day.report();
}
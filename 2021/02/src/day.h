//
// Created by snyg9u on 2023-11-17.
//

#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H


#include <vector>
enum Direction {
    UNKNOWN=1,
    FORWARD=2,
    DOWN=3,
    UP=4
};
struct Command
{
    Direction dir;
    int steps;

};

class Day {
public:
    Day(std::vector<std::string> data);
    void runA(bool secondData=false);
    void runB();
    void report();
private:
    Direction toCommand(std::string line) {
        if(line == "forward") return Direction::FORWARD;
        if(line == "down") return Direction::DOWN;
        if(line == "up") return Direction::UP;
        return Direction::UNKNOWN;
    }
    std::vector<Command> m_input;
    int m_resultA;
    int m_resultB;
};


#endif //ADVENTOFCODE_DAY_H

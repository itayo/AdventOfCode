#include <iostream>
#include <fileread.h>
#include "day.h"
#include <fileread.h>

Day::Day(std::vector<std::string> data) : m_resultA(0), m_resultB(0) {
    for (std::string line: data) {
        std::vector<std::string> words = aoc::Tokenize(line);
        Command command;
        command.dir = toCommand(words[0]);
        command.steps = atoi(words[1].c_str());
        m_input.push_back(command);
    }
}

void Day::runA(bool secondData) {
    int forward = 0;
    int depth = 0;
    for (Command cmd: m_input) {
        switch (cmd.dir) {
            case DOWN:
                depth += cmd.steps;
                break;
            case UP:
                depth -= cmd.steps;
                break;
            case FORWARD:
                forward += cmd.steps;
                break;
        }
    }
    m_resultA = depth * forward;

}

void Day::runB() {
    int forward = 0;
    int depth = 0;
    int aim = 0;
    for (Command cmd: m_input) {
        switch (cmd.dir) {
            case DOWN:
                aim += cmd.steps;
                break;
            case UP:
                aim -= cmd.steps;
                break;
            case FORWARD:
                forward += cmd.steps;
                depth += aim*cmd.steps;
                break;
        }
    }
    m_resultB = depth * forward;
}

void Day::report() {
    std::cout << "2021-01-2: " << ((m_resultA == 0) ? "N/A" : std::to_string(m_resultA)) << std::endl;
    std::cout << "2021-01-2: " << ((m_resultB == 0) ? "N/A" : std::to_string(m_resultB));
}
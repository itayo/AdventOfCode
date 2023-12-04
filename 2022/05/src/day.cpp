#include "day.h"
#include <algorithm>
#include <iostream>
#include <stack>

void Day::PrepareData()
{
    int breaker = 0;
    std::vector<std::string> stacks;
    for (int i = 0; i<m_data.size(); ++i) {
        if (m_data[i]!="") continue;
        breaker = i;
        break;
    }
    for (int i = 0; i<breaker; ++i) stacks.push_back(m_data[i]);
    std::reverse(stacks.begin(), stacks.end());
    aoc.StringReplace(stacks[0], {
            {"  ", " "},
            {" 1", "1"}});
    int numberOfStacks = 0;
    for (auto val: aoc.StringSplit(stacks[0], ' ')) {
        numberOfStacks = std::max(numberOfStacks, std::stoi(val));
    }
    m_stacksA = std::vector<std::stack<char>>(numberOfStacks);
    m_stacksB = std::vector<std::stack<char>>(numberOfStacks);
    stacks.erase(stacks.begin());
    for (auto line: stacks) {
        for (int i = 0; i<numberOfStacks; ++i) {
            if (line[1+(i*4)]!=' ') {
                m_stacksA[i].push(line[1+(i*4)]);
                m_stacksB[i].push(line[1+(i*4)]);
            }
        }

    }

    for (auto line: stacks) std::cout << line << std::endl;
    for (int i = breaker+1; i<m_data.size(); ++i) {
        std::string::size_type moveIterator = m_data[i].find("move ");
        if (i!=std::string::npos)
            m_data[i].erase(moveIterator, std::string("move ").length());

        std::string::size_type fromIterator = m_data[i].find("from ");
        if (i!=std::string::npos)
            m_data[i].erase(fromIterator, std::string("from ").length());

        std::string::size_type toIterator = m_data[i].find("to ");
        if (i!=std::string::npos)
            m_data[i].erase(toIterator, std::string("to ").length());
        auto cmd = aoc.StringSplit(m_data[i], ' ');
        tCommand command;
        command.amount = std::stoi(cmd[0]);
        command.from = std::stoi(cmd[1])-1;
        command.to = std::stoi(cmd[2])-1;
        m_commands.emplace_back(command);
    }
}

void Day::RunA(bool secondData)
{
    for (auto command: m_commands) {
        for (int i = 0; i<command.amount; ++i) {
            m_stacksA[command.to].push(m_stacksA[command.from].top());
            m_stacksA[command.from].pop();
        }
    }
    for (auto stack: m_stacksA) {
        m_resultA += stack.top();
    }
}

void Day::RunB()
{
    for (auto command: m_commands) {
        std::stack<char> middle;
        for (int i = 0; i<command.amount; ++i) {
            middle.push(m_stacksB[command.from].top());
            m_stacksB[command.from].pop();

        }
        while(!middle.empty()) {
            m_stacksB[command.to].push(middle.top());
            middle.pop();
        }
    }

    for (auto stack: m_stacksB) {
        m_resultB += stack.top();
    }
}

void Day::Report()
{
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
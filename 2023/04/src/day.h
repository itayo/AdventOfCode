#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include <vector>
#include "AoC/aoc.h"
#include <string>
#include <regex>
#include "AoC/Grid2D.h"

struct ScratchCard {
public:
    int id;
    std::vector<int> winningNumbers;
    std::vector<int> myNumbers;
    std::vector<int> GetWinners() {
        std::vector<int> ret;
        for (auto number: winningNumbers) {
            if (std::find(myNumbers.begin(), myNumbers.end(), number) != myNumbers.end())
                ret.push_back(number);
        }
        return ret;
    }
};

class Day {
public:
    Day(std::vector<std::string> data) : m_resultA(0), m_resultB(0), m_data(data) {
        aoc.StringReplace(m_data, std::vector<AoC::tStringToReplace>{
                {"Card ", ""},
                {": ",    ":"},
                {" :",    ":"},
                {"  ",    " "},
                {" |",    "|"},
                {"| ",    "|"}});
        for (auto line: m_data) {
            ScratchCard card;
            card.id = std::stoi(aoc.StringSplit(line, ':')[0]);
            std::vector<std::string> numbers = aoc.StringSplit(aoc.StringSplit(line, ':')[1], '|');
            std::vector<std::string> winners = aoc.StringSplit(numbers[0], ' ');
            std::vector<std::string> mine = aoc.StringSplit(numbers[1], ' ');
            for(std::string number: winners) {card.winningNumbers.push_back(std::stoi(number));}
            for(std::string number: mine) {card.myNumbers.push_back(std::stoi(number));}
            m_cards.push_back(card);
        }
    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    int ResultA() { return m_resultA; }

    int ResultB() { return m_resultB; }

private:
    AoC::AoC aoc;
    std::vector<std::string> m_data;
    std::vector<ScratchCard> m_cards;
    int m_resultA;
    int m_resultB;
};


#endif //ADVENTOFCODE_DAY_H

#include <iostream>
#include "day.h"
#include <algorithm>

void Day::PrepareData() {
    for (std::string line: m_data) {
        std::vector<std::string> lineData = aoc.StringSplit(line, ' ');
        tGame game;
        switch (lineData[0][0]) {
            case 'A':
                game.other = RPS::ROCK;
                break;
            case 'B':
                game.other = RPS::PAPER;
                break;
            case 'C':
                game.other = RPS::SCISSOR;
                break;
        }
        game.me = lineData[1][0];
        m_preparedData.push_back(game);
    }
}

int Day::DetermineWinner(RPS me, RPS other) {
    if(me == other) return 3;
    if(me == RPS::ROCK && other == RPS::SCISSOR) return 6;
    if(me == RPS::SCISSOR && other == RPS::PAPER) return 6;
    if(me == RPS::PAPER && other == RPS::ROCK) return 6;
    return 0;

}

RPS Day::DetermineMyHand(RPS other, char outcome) {
    RPS myHand;
    switch(outcome)
    {
        case 'X':
            if(other == RPS::ROCK) return RPS::SCISSOR;
            if(other == RPS::PAPER) return RPS::ROCK;
            if(other == RPS::SCISSOR) return RPS::PAPER;
            break;
        case 'Z':
            if(other == RPS::ROCK) return RPS::PAPER;
            if(other == RPS::PAPER) return RPS::SCISSOR;
            if(other == RPS::SCISSOR) return RPS::ROCK;
            break;
        default:
            break;
    }
    return other;
}


void Day::RunA(bool secondData) {
    m_resultA = 0;
    for(auto game: m_preparedData) {
        switch(game.me) {
            case 'X':
                m_resultA += RPS::ROCK + DetermineWinner(RPS::ROCK, game.other);
                break;
            case 'Y':
                m_resultA += RPS::PAPER + DetermineWinner(RPS::PAPER, game.other);
                break;
            case 'Z':
                m_resultA += RPS::SCISSOR + DetermineWinner(RPS::SCISSOR, game.other);
                break;
        }
    }
}

void Day::RunB() {
    for(auto game: m_preparedData) {
           RPS myHand = DetermineMyHand(game.other, game.me);
           m_resultB += myHand + DetermineWinner(myHand, game.other);
    }

}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
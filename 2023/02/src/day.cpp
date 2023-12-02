#include <iostream>
#include "day.h"
#include <algorithm>

void Day::PrepareGame(std::string line) {
    tGame game;
    auto gameStrings = aoc.StringSplit(line, ':');
    game.id = std::stoi(aoc.StringSplit(gameStrings[0], ' ')[1]);
    auto gameDraws = aoc.StringSplit(gameStrings[1], ';');
    for (auto roundDraws: gameDraws) {
        auto draws = aoc.StringSplit(roundDraws, ',');
        int r = 0, g = 0, b = 0;
        for (auto draw: draws) {
            auto temp = aoc.StringSplit(draw, ' ');
            switch (temp[1][0]) {
                case 'r':
                    r = std::stoi(temp[0]);
                    break;
                case 'g':
                    g = std::stoi(temp[0]);
                    break;
                case 'b':
                    b = std::stoi(temp[0]);
                    break;
            }
        }
        game.draws.push_back({r, g, b});
    }
    int r = 0, g = 0, b = 0;
    for (auto draw: game.draws) {
        game.maximum.red = game.maximum.red < draw.red ? draw.red : game.maximum.red;
        game.maximum.green = game.maximum.green < draw.green ? draw.green : game.maximum.green;
        game.maximum.blue = game.maximum.blue < draw.blue ? draw.blue : game.maximum.blue;
    }
    m_games.push_back(game);


}


void Day::PrepareData() {
    std::vector<AoC::tStringToReplace> Cleans = {{": ", ":"},
                                                 {", ", ","},
                                                 {"; ", ";"}};
    aoc.StringReplace(m_data, Cleans);
    for (std::string line: m_data) {
        PrepareGame(line);
    }
    std::cout << "data prepped";
}


void Day::RunA(bool secondData) {
    tDraw max{12, 13, 14};
    m_resultA = 0;
    for (auto game: m_games) {
        if (game.maximum.red <= max.red && game.maximum.green <= max.green && game.maximum.blue <= max.blue) {
            m_resultA += game.id;
        }
    }
}

void Day::RunB() {
    m_resultB = 0;
    for (auto game: m_games) {
        m_resultB += game.maximum.red * game.maximum.green * game.maximum.blue;
    }

}

void Day::Report() {
    std::cout << "2021-01-1: " << m_resultA << std::endl;
    std::cout << "2021-01-2: " << m_resultB;
}
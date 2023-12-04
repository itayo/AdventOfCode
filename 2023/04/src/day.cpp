#include <iostream>
#include "day.h"


void Day::PrepareData() {

}


void Day::RunA(bool secondData) {
    for (ScratchCard card: m_cards) {
        int winningNumbers = card.GetWinners().size();
        int points = 0;
        if (winningNumbers > 0) {
            points = 1;
            winningNumbers -= 1;
        }
        for (; winningNumbers > 0; winningNumbers--) { points *= 2; }
        m_resultA += points;
    }

}

void Day::RunB() {
    std::vector<int> cards(m_cards.size(), 1);
    for(int card=0; card < cards.size(); ++card) {
        auto wins = m_cards[card].GetWinners().size();
        for(int cardgen = card +1; cardgen <= card + wins;++cardgen) {
            cards[cardgen] += cards[card];
        }
    }
    for (auto& n : cards) { m_resultB += n;}
}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
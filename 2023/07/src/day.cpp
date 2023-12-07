#include <iostream>
#include <algorithm>
#include "day.h"
#define UNUSED(x)  (void)((x))
void Day::PrepareData() {

  for (auto line : m_data) {
    auto words = aoc.StringSplit(line, ' ');
    auto value = aoc.GetAllIntegersU64(words[1]);
    std::vector<int> rankerA;
    std::vector<int> rankerB;
    auto rankA = RankHandA(words[0], rankerA);
    auto rankB = RankHandB(words[0], rankerB);

    m_handsA.emplace_back(words[0], value[0], rankA, rankerA);
    m_handsB.emplace_back(words[0], value[0], rankB, rankerB);
  }
  std::sort(m_handsA.begin(), m_handsA.end());
  std::sort(m_handsB.begin(), m_handsB.end());

}
int Day::CardToIntA(char card) {
  switch (card) {
    case 'A': return 14;
    case 'K': return 13;
    case 'Q': return 12;
    case 'J': return 11;
    case 'T': return 10;
    default: return card - '0';
  }
}

int Day::CardToIntB(char card) {
  switch (card) {
    case 'A': return 14;
    case 'K': return 13;
    case 'Q': return 12;
    case 'J': return 1;
    case 'T': return 10;
    default: return card - '0';
  }
}

HandRank Day::RankHandA(const std::string &p_hand,
                        std::vector<int> &p_ranker) {
  auto currentHand = p_hand;
  std::sort(currentHand.begin(), currentHand.end());
  std::vector<int> counts(6, 0);
  char card = '\0';
  int count = 1;
  for (auto rankCard : p_hand) { p_ranker.push_back(CardToIntA(rankCard)); }
  for (auto currentCard : currentHand) {
    if (currentCard != card) {
      if (count != 1) {
        counts[count]++;
      }
      count = 1;
      card = currentCard;
    } else {
      count++;
    }
  }
  counts[count]++;
  if (counts[5] == 1) {
    return FiveOfAKind;
  }
  if (counts[4] == 1) {
    return FourOfAKind;
  }
  if (counts[3] == 1 && counts[2] == 1) {
    return FullHouse;
  }
  if (counts[3] == 1) {
    return ThreeOfAKind;
  }
  if (counts[2] == 2) {
    return TwoPair;
  }
  if (counts[2] == 1) {
    return OnePair;
  }
  return HiCard;
}

HandRank Day::RankHandB(const std::string &p_hand,
                        std::vector<int> &p_ranker) {
  auto currentHand = p_hand;
  std::sort(currentHand.begin(), currentHand.end());
  std::vector<int> counts(6, 0);
  char card = '\0';
  int count = 1;
  int jacks = 0;
  for (auto rankCard : p_hand) { p_ranker.push_back(CardToIntB(rankCard)); }
  for (auto currentCard : currentHand) {
    if (currentCard == 'J') { ++jacks; }
    else {
      if (currentCard != card) {
        if (count != 1) {
          counts[count]++;
        }
        count = 1;
        card = currentCard;
      } else {
        count++;
      }
    }
  }
  counts[count]++;
  if (counts[5] == 1) { return FiveOfAKind; }
  switch (jacks) {
    case 0:
      if (counts[4] == 1) { return FourOfAKind; }
      if (counts[3] == 1 && counts[2] == 1) { return FullHouse; }
      if (counts[3] == 1) { return ThreeOfAKind; }
      if (counts[2] == 2) { return TwoPair; }
      if (counts[2] == 1) { return OnePair; }
      return HiCard;
    case 1:
      if (counts[4] == 1) { return FiveOfAKind; }
      if (counts[3] == 1 ) { return FourOfAKind; }
      if (counts[2] == 2) { return FullHouse; }
      if (counts[2] == 1) { return ThreeOfAKind; }
      return OnePair;
    case 2:
      if (counts[4] == 1) { return FiveOfAKind; }
      if (counts[3] == 1) { return FiveOfAKind; }
      if (counts[2] == 1 ) { return FourOfAKind; }
      return ThreeOfAKind;
    case 3:
      if (counts[4] == 1) { return FiveOfAKind; }
      if (counts[3] == 1) { return FiveOfAKind; }
      if (counts[2] == 1 ) { return FiveOfAKind; }
      return FourOfAKind;
    case 4:
    case 5:
      return FiveOfAKind;
    default:
      throw "We shouldn't reach here";

  }
}

void Day::RunA(bool secondData) {
  uint64_t multiplier = 1;
  for (auto hand : m_handsA) {
    m_resultA += multiplier * hand.value;
    multiplier++;
  }

}

void Day::RunB() {
  uint64_t multiplier = 1;
  for (auto hand : m_handsB) {
    m_resultB += multiplier * hand.value;
    multiplier++;
  }
}

void Day::Report() {
  std::cout << "Part A: " << m_resultA << std::endl;
  std::cout << "Part B: " << m_resultB;
}
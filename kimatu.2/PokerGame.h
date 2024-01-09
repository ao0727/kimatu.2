#pragma once

#include "Shoe.h"

class PokerGame {
private:
    Shoe deck;
    int playerHand[5];

public:
    PokerGame();
    void dealCards();
    void showHand() const;
    void replaceCards();
    void evaluateHand();
};

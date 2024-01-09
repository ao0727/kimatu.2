#pragma once

#include <iostream>
#include <algorithm>
#include <random>

class Shoe {
private:
    int _cardNumbers[52]; // カード番号の配列
    const char* _cardMarks[52]; // マーク情報の配列
    int _cardNum;

public:
    enum SHOW_TYPE
    {
        CARD_ONLY,
        ALL
    };

    Shoe();
    int takeCard();
    void showShoe(SHOW_TYPE type = CARD_ONLY) const;

private:
    void _initCardShoe();
    void _shuffle();
};

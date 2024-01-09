#pragma once

#include <iostream>
#include <algorithm>
#include <random>

class Shoe {
private:
    int _cardNumbers[52]; // �J�[�h�ԍ��̔z��
    const char* _cardMarks[52]; // �}�[�N���̔z��
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

#include "Shoe.h"
#define CARD_NUM 52
using namespace std;

Shoe::Shoe() {
    _initCardShoe();
    _shuffle();
}

void Shoe::_initCardShoe() {
    _cardNum = CARD_NUM;

    // �J�[�h�ԍ���������
    for (int i = 0; i < _cardNum; ++i) {
        _cardNumbers[i] = i + 1;  // 1?52�܂ł̔ԍ������蓖�Ă�
    }

    // �}�[�N�����ʂ���
    for (int i = 0; i < _cardNum; ++i) {
        if (_cardNumbers[i] <= 13) {
            _cardMarks[i] = "H";  
        }
        else if (_cardNumbers[i] <= 26) {
            _cardMarks[i] = "D"; 
        }
        else if (_cardNumbers[i] <= 39) {
            _cardMarks[i] = "S";  
        }
        else {
            _cardMarks[i] = "C";   
        }
    }
}

void Shoe::_shuffle() {
    random_device rd;
    mt19937 g(rd());
    shuffle(_cardNumbers, _cardNumbers + _cardNum, g);
}

int Shoe::takeCard() {
    if (_cardNum <= 0) {
        _initCardShoe();
        _shuffle();
    }
    _cardNum--;

    int cardNumber = (_cardNumbers[_cardNum] - 1) % 13 + 1; // �J�[�h�ԍ���1����13�ɕϊ�
    cout << _cardMarks[_cardNum];
    if (cardNumber == 1) {
        cout << "A ";
    }
    else if (cardNumber == 11) {
        cout << "J ";
    }
    else if (cardNumber == 12) {
        cout << "Q ";
    }
    else if (cardNumber == 13) {
        cout << "K ";
    }
    else {
        cout << cardNumber << " ";
    }

    return _cardNumbers[_cardNum];
}


void Shoe::showShoe(SHOW_TYPE type) const {
    int loopCount = (type == CARD_ONLY) ? _cardNum : 52;
    for (int i = 0; i < loopCount; ++i) {
        if (i < _cardNum) {
            int cardNumber = (_cardNumbers[i] - 1) % 13 + 1; // �J�[�h�ԍ���1����13�ɕϊ�
            const char* suits[] = { "Hearts", "Diamonds", "Spades", "Clubs" };
            const char* suit = suits[(_cardNumbers[i] - 1) / 13]; // �J�[�h�̃X�[�g���擾

            cout << suit << " ";
            if (cardNumber == 1) {
                cout << "A ";
            }
            else if (cardNumber == 11) {
                cout << "J ";
            }
            else if (cardNumber == 12) {
                cout << "Q ";
            }
            else if (cardNumber == 13) {
                cout << "K ";
            }
            else {
                cout << cardNumber << " ";
            }
        }
    }
   
}
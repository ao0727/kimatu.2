#include "PokerGame.h"
#include <iostream>
#include <sstream>

using namespace std;

PokerGame::PokerGame() {
    dealCards();
    //showHand();
    replaceCards();
    showHand();
    evaluateHand();
}

void PokerGame::dealCards() {
    for (int i = 0; i < 5; ++i) {
        playerHand[i] = deck.takeCard();
    }
}

void PokerGame::showHand() const {
    cout << "Current Hand: ";
    for (int i = 0; i < 5; ++i) {
        // カードの数字とスートを表示する処理を追加する
        char suit;
        switch (playerHand[i] / 13) {
        case 0: suit = 'C'; break; 
        case 1: suit = 'D'; break; 
        case 2: suit = 'H'; break;
        case 3: suit = 'S'; break;
        }
        int cardNumber = playerHand[i] % 13 + 1;
        if (cardNumber == 1) {
            cout << "A" << suit << " ";
        }
        else if (cardNumber == 11) {
            cout << "J" << suit << " ";
        }
        else if (cardNumber == 12) {
            cout << "Q" << suit << " ";
        }
        else if (cardNumber == 13) {
            cout << "K" << suit << " ";
        }
        else {
            cout << cardNumber << suit << " ";
        }
    }
   
}


void PokerGame::replaceCards() {
    cout << "交換するカードを選択(位置1～5を入力。例  2 4 5)";
    string input;
    getline(cin, input);

    istringstream iss(input);
    int position;
    while (iss >> position) {
        if (position >= 1 && position <= 5) {
            playerHand[position - 1] = deck.takeCard();
        }
    }
}

void PokerGame::evaluateHand() {
    cout << "" << endl;
}

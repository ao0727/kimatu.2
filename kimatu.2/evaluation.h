#include <algorithm>

using namespace std;
// ポーカーハンドの役を表す列挙型
enum class PokerHand {
    HIGH_CARD,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
};

void PokerGame::evaluateHand() {
    // 手札をソートする
    std::sort(std::begin(playerHand), std::end(playerHand));

    // 役の判定を行う
    PokerHand handRank = PokerHand::HIGH_CARD;

    bool isFlush = true; // フラッシュかどうかを示すフラグ
    bool isStraight = true; // ストレートかどうかを示すフラグ
    
    // フラッシュの判定
    for (int i = 1; i < 5; ++i) {
        if (playerHand[i] / 13 != playerHand[0] / 13) {
            isFlush = false;
            break;
        }
    }//1枚目と違うスートがないか



    // ストレートの判定
    for (int i = 1; i < 5; ++i) {
        if (playerHand[i] % 13 != playerHand[i - 1] % 13 + 1) {
            isStraight = false;
            break;
        }
    }//横との数との差が1か


    bool hasOnePair = false;
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (playerHand[i] % 13 == playerHand[j] % 13) {
                hasOnePair = true; // ペアが見つかった
                break; // ペアが見つかったらループを抜ける
            }
        }
        if (hasOnePair) {
            break; // ペアが見つかったら外側のループも抜ける
        }
    }//余りが一緒かどうかで判定

    bool hasTwoPair(const int playerHand[]) {
        int pairCount = 0; // ペアの数をカウントする変数

        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                // 同じ数字を持つカードが見つかった場合
                if (playerHand[i] % 13 == playerHand[j] % 13) {
                    pairCount++; // ペアが見つかったのでカウントを増やす
                    i = j; // 同じ数字のカードを1つ見つけたので次のカードへ移動
                    break; // ペアが見つかったので内側のループを抜ける
                }
            }
        }

        return pairCount >= 2; // 2つ以上のペアがあるかどうかを返す
    }


    bool hasTwoPairs = hasTwoPair(playerHand);
    if (isFlush && isStraight) {
        handRank = PokerHand::STRAIGHT_FLUSH;
    }
    else if (isFlush) {
        handRank = PokerHand::FLUSH;
    }
    else if (isStraight) {
        handRank = PokerHand::STRAIGHT;
    }
    else if (hasOnePair) {
        handRank = PokerHand::ONE_PAIR; 
    }
    else if (hasTwoPair) {
        handRank = PokerHand::TWO_PAIR;
    }
    else {
        // 他の役の判定を追加する
        
    }

    // 役を表示する
    switch (handRank) {
    case PokerHand::HIGH_CARD:
        cout << "High Card..." << endl;
        break;
    case PokerHand::ONE_PAIR:
        cout << "One Pair" << endl;
        break;
    case PokerHand::TWO_PAIR:
        cout << "Two Pair" << endl;
        break;
    case PokerHand::THREE_OF_A_KIND:
        cout << "Three of a Kind!" << endl;
        break;
    case PokerHand::STRAIGHT:
        cout << "Straight!" << endl;
        break;
    case PokerHand::FLUSH:
        cout << "Flush!" << endl;
        break;
    case PokerHand::FULL_HOUSE:
        cout << "Full House!!" << endl;
        break;
    case PokerHand::FOUR_OF_A_KIND:
        cout << "Four of a Kind!!" << endl;
        break;
    case PokerHand::STRAIGHT_FLUSH:
        cout << "Straight Flush!!!!" << endl;
        break;
    default:
        break;
    }
}

#include <algorithm>

using namespace std;
// �|�[�J�[�n���h�̖���\���񋓌^
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
    // ��D���\�[�g����
    std::sort(std::begin(playerHand), std::end(playerHand));

    // ���̔�����s��
    PokerHand handRank = PokerHand::HIGH_CARD;

    bool isFlush = true; // �t���b�V�����ǂ����������t���O
    bool isStraight = true; // �X�g���[�g���ǂ����������t���O
    
    // �t���b�V���̔���
    for (int i = 1; i < 5; ++i) {
        if (playerHand[i] / 13 != playerHand[0] / 13) {
            isFlush = false;
            break;
        }
    }//1���ڂƈႤ�X�[�g���Ȃ���



    // �X�g���[�g�̔���
    for (int i = 1; i < 5; ++i) {
        if (playerHand[i] % 13 != playerHand[i - 1] % 13 + 1) {
            isStraight = false;
            break;
        }
    }//���Ƃ̐��Ƃ̍���1��


    bool hasOnePair = false;
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (playerHand[i] % 13 == playerHand[j] % 13) {
                hasOnePair = true; // �y�A����������
                break; // �y�A�����������烋�[�v�𔲂���
            }
        }
        if (hasOnePair) {
            break; // �y�A������������O���̃��[�v��������
        }
    }//�]�肪�ꏏ���ǂ����Ŕ���

    bool hasTwoPair(const int playerHand[]) {
        int pairCount = 0; // �y�A�̐����J�E���g����ϐ�

        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                // �������������J�[�h�����������ꍇ
                if (playerHand[i] % 13 == playerHand[j] % 13) {
                    pairCount++; // �y�A�����������̂ŃJ�E���g�𑝂₷
                    i = j; // ���������̃J�[�h��1�������̂Ŏ��̃J�[�h�ֈړ�
                    break; // �y�A�����������̂œ����̃��[�v�𔲂���
                }
            }
        }

        return pairCount >= 2; // 2�ȏ�̃y�A�����邩�ǂ�����Ԃ�
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
        // ���̖��̔����ǉ�����
        
    }

    // ����\������
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

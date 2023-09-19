#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Card {
    int value;
    char suit;
    bool operator==(const Card &other) const {
        return value == other.value && suit == other.suit;
    }
};

bool compareCards(const Card &a, const Card &b) {
    return a.value < b.value;
}

int main() {
    int n;
    cin >> n;

    map<int, vector<Card>> cardsByValue;
    map<char, vector<Card>> cardsBySuit;

    for (int i = 0; i < n; i++) {
        int value, cnt;
        char suit;
        cin >> value >> cnt >> suit;

        for (int j = 0; j < cnt; j++) {
            Card card;
            card.value = value;
            card.suit = suit;
            cardsByValue[value].push_back(card);
            cardsBySuit[suit].push_back(card);
        }
    }

    int score = 0;

    while (true) {
        bool found = false;

        // 遍历每个花色
        for (char suit : "SHDC") {
            if (cardsBySuit[suit].size() < 5) {
                continue;
            }

            vector<Card> cards = cardsBySuit[suit];
            sort(cards.begin(), cards.end(), compareCards);

            // 遍历同花色的牌，查找同花顺
            for (int i = 0; i <= cards.size() - 5; i++) {
                bool isStraightFlush = true;

                for (int j = 1; j < 5; j++) {
                    if (cards[i + j].value != cards[i].value + j) {
                        isStraightFlush = false;
                        break;
                    }
                }

                if (isStraightFlush) {
                    // 找到同花顺，增加得分
                    score++;
                    for (int j = 0; j < 5; j++) {
                        auto it = remove(cardsBySuit[suit].begin(), cardsBySuit[suit].end(), cards[i + j]);
                        cardsBySuit[suit].erase(it, it+1);
                    }
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            // 如果没有找到同花顺，则结束循环
            break;
        }
    }

    cout << score << endl;

    return 0;
}

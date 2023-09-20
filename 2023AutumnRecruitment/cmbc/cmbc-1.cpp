#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countCombinations(int n, vector<int> cards) {
    // Base case: If n is 1, there are as many combinations as there are cards.
    if (n == 1) {
        return cards.size();
    }

    int count = 0;
    for (int i = 0; i < cards.size(); i++) {
        // Skip 0 as the first digit when n > 1.
        if (n > 1 && cards[i] == 0) {
            continue;
        }

        // Create a copy of the cards vector without the chosen card.
        vector<int> remaining_cards = cards;
        remaining_cards.erase(remaining_cards.begin() + i);

        // Recursively count combinations for n-1 with remaining cards.
        count += countCombinations(n - 1, remaining_cards);
    }

    return count;
}

int main() {
    vector<int> cards = {1, 2, 5, 8, 0, 6, 4};
    int n = 1;

    int result = countCombinations(n, cards);
    cout << "Number of unique " << n << "-digit combinations: " << result << endl;

    return 0;
}

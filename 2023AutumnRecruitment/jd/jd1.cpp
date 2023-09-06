#include <iostream>
#include <vector>
using namespace std;

char checkWinner(vector<string>& board) {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.')
            return board[i][0];

        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.')
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.')
        return board[0][2];

    return 'd'; // draw
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        vector<string> board(3);
        for (int j = 0; j < 3; j++) {
            cin >> board[j];
        }
        char winner = checkWinner(board);
        if (winner == 'o') {
            cout << "yukari" << endl;
        } else if (winner == '*') {
            cout << "kou" << endl;
        } else {
            cout << "draw" << endl;
        }
    }

    return 0;
}

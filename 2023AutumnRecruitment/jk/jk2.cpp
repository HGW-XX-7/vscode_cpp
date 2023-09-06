#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//第一题
int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    while (N > 1) {
        vector<vector<int>> newMatrix(N / 2, vector<int>(N / 2));
        for (int i = 0; i < N; i += 2) {
            for (int j = 0; j < N; j += 2) {
                vector<int> elements = {matrix[i][j], matrix[i][j + 1], matrix[i + 1][j], matrix[i + 1][j + 1]};
                sort(elements.begin(), elements.end());
                newMatrix[i / 2][j / 2] = elements[2];
            }
        }
        matrix = newMatrix;
        N /= 2;
    }
    cout << matrix[0][0] << endl;
    return 0;
}

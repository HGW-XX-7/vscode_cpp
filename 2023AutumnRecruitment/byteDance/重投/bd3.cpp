#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;

int main() {
    string s, t;
    int k;
    cin >> s >> t >> k;

    int n = s.size();
    int m = t.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

    // Initialize dp array
    dp[0][0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int kk = 0; kk <= k; kk++) {
                // Transition from dp[i-1][j][kk]
                if (i > 0 && kk > 0) {
                    dp[i][j][kk] = (dp[i][j][kk] + dp[i - 1][j][kk - 1]) % MOD;
                }
                // Transition from dp[i][j-1][kk]
                if (j > 0 && kk > 0) {
                    dp[i][j][kk] = (dp[i][j][kk] + dp[i][j - 1][kk - 1]) % MOD;
                }
                // Transition from dp[i-1][j][kk] (if s[i-1] == t[j-1])
                if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) {
                    dp[i][j][kk] = (dp[i][j][kk] + dp[i - 1][j - 1][kk]) % MOD;
                }
            }
        }
    }

    cout << dp[n][m][k] << endl;

    return 0;
}

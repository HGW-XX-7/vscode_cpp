#include <iostream>
#include <vector>

int minInsertionsToBalance(const std::string& s) {
    int n = s.length();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // 遍历字符串，计算dp数组
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            if (s[i] == '(' && s[j] == ')'|| s[i] == '[' && s[j] == ']') {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = std::min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    std::string input = "(([[])";
    int result = minInsertionsToBalance(input);
    std::cout << "Minimum insertions required: " << result << std::endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // 创建一个二维数组dp，用于存储到达每个位置的最小路径和
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 初始化dp数组的第一个元素
    dp[0][0] = grid[0][0];

    // 初始化第一行和第一列
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // 填充dp数组
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // dp[m-1][n-1] 包含最终的最小路径和
    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> grid = {{1, 3, 5, 9},
                                {8, 1, 3, 4},
                                {5, 0, 6, 1},
                                {8, 8, 4, 0}};

    int result = minPathSum(grid);
    cout << result << endl;

    return 0;
}

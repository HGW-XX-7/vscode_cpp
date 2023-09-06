#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//第三题
int rotMinutes(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    // 定义四个方向的偏移量，分别是上、下、左、右
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> rotten; // 存储腐烂的苹果坐标
    queue<pair<int, int>> fresh; // 存储新鲜苹果坐标
    // 遍历网格，初始化队列
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) {
                rotten.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh.push({i, j});
            }
        }
    }
    int minutes = 0; // 经过的分钟数
    while (!rotten.empty() && !fresh.empty()) {
        int size = rotten.size();
        for (int i = 0; i < size; ++i) {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();
            for (int j = 0; j < 4; ++j) {
                int newX = x + dirs[j][0];
                int newY = y + dirs[j][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // 腐烂新鲜苹果
                    rotten.push({newX, newY});
                    fresh.pop(); // 新鲜苹果变腐烂
                }
            }
        }
        ++minutes;
    }
    return fresh.empty() ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int result = rotMinutes(grid);
    cout << "Output: " << result << endl;
    
    return 0;
}

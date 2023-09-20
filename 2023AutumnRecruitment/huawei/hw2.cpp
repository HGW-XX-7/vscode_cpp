#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 定义每个同学的坐标
struct Coordinate {
    int row;
    int col;
};

// 判断一个坐标是否在边界内
bool isInBounds(int row, int col, int m, int n) {
    return row >= 0 && row < m && col >= 0 && col < n;
}

// 计算最优传球次数
int getMinPassCount(vector<vector<int>>& classGrid) {
    int m = classGrid.size();
    int n = classGrid[0].size();

     // 定义四个方向：上、下、左、右
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // 定义队列和访问数组
    queue<Coordinate> q;
    vector<vector<int>> dist(m, vector<int>(n, -1));

    // 将第一列男同学入队，并初始化距离为0
    for (int i = 0; i < m; i++) {
        if (classGrid[i][0] == 1) {
            q.push({i, 0});
            dist[i][0] = 0;
        }
    }

    // 进行BFS搜索，更新距离
    while (!q.empty()) {
        Coordinate curr = q.front();
        q.pop();

        int currRow = curr.row;
        int currCol = curr.col;

        // 到达最后一列男同学
        if (currCol == n - 1 && classGrid[currRow][currCol] == 1) {
            return dist[currRow][currCol];
        }

        // 从当前位置传球
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + dx[i];
            int newCol = currCol + dy[i];

            // 判断新坐标是否在边界内、是否为男同学，且未被访问过
            if (isInBounds(newRow, newCol, m, n) && classGrid[newRow][newCol] == 1 && dist[newRow][newCol] == -1) {
                q.push({newRow, newCol});
                dist[newRow][newCol] = dist[currRow][currCol] + 1;
            }
        }
    }

    // 无法传球到最后一列男同学
    return -1;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> classGrid(m, vector<int>(n));

    // 读取班级同学队伍分布情况
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> classGrid[i][j];
        }
    }

    // 获取最优传球次数并输出
    int minPassCount = getMinPassCount(classGrid);
    cout << minPassCount << endl;

    return 0;
}

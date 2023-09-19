#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countOnes(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 2 == 1)
            count++;
        num >>= 1;
    }
    return count;
}

int maxOr(vector<vector<int>>& arrays, int k) {
    int n = arrays[0].size();
    vector<vector<int>> prefixes(3, vector<int>(n, 0));

    // 计算前缀数组
    for (int i = 0; i < 3; ++i) {
        prefixes[i][0] = arrays[i][0];
        for (int j = 1; j < n; ++j) {
            prefixes[i][j] = arrays[i][j] | prefixes[i][j - 1];
        }
    }

    vector<pair<int, int>> prefixOr[3];

    // 构建前缀或数组
    for (int i = 0; i < 3; ++i) {
        prefixOr[i] = {{0, prefixes[i][0]}};
        for (int j = 1; j < n; ++j) {
            if (prefixes[i][j] != prefixes[i][j - 1]) {
                prefixOr[i].emplace_back(j, prefixes[i][j]);
            }
        }
    }

    int ans = 0;

    // 枚举三个前缀数组的长度
    for (int i = 0; i < prefixOr[0].size(); ++i) {
        for (int j = 0; j < prefixOr[1].size(); ++j) {
            for (int k = 0; k < prefixOr[2].size(); ++k) {
                int len = prefixOr[0][i].first + prefixOr[1][j].first + prefixOr[2][k].first + 3;
                if (len <= k) {
                    int orResult = prefixOr[0][i].second | prefixOr[1][j].second | prefixOr[2][k].second;
                    ans = max(ans, countOnes(orResult));
                } else {
                    break;  // 如果长度已经超过k，就不需要再枚举更长的前缀了
                }
            }
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arrays(3, vector<int>(n));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arrays[i][j];
        }
    }

    int result = maxOr(arrays, k);
    cout << result << endl;

    return 0;
}

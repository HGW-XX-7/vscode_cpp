#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<numeric>
using namespace std;

int sum;
int min_diff = INT_MAX;

void dfs(vector<vector<int>>& cake, int row, int sum1, int sum2) {
    if (row == cake.size()) {
        min_diff = min(min_diff, abs(sum1 - sum2));
        return;
    }

    dfs(cake, row + 1, sum1 + accumulate(cake[row].begin(), cake[row].end(), 0), sum2);
    dfs(cake, row + 1, sum1, sum2 + accumulate(cake[row].begin(), cake[row].end(), 0));
}

int main()
{
    int n,m;
    cin >> n >>m;
    int test[n][m];
    vector<vector<int>> cake(n, vector<int>(m));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >>cake[i][j]; 
        }
    }
    
    // 计算整个蛋糕的美味度之和
    sum = accumulate(cake[0].begin(), cake[0].end(), 0);

    // 进行DFS搜索
    dfs(cake, 1, sum, 0);

    // 输出结果
    cout << min_diff << endl;
    return 0;
}

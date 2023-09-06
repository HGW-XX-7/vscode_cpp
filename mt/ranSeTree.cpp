#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 100005;

vector<int> adj[N]; // 存储树的邻接关系
vector<int> a(N);   // 存储每个节点的权值
vector<vector<int>> dp(N, vector<int>(2, 0)); // N行 2列 值0 dp[i][0] 表示不染红节点 i 的最大节点数，dp[i][1] 表示染红节点 i 的最大节点数

bool isPerfectSquare(int x) {
    int root = sqrt(x);
    return root * root == x;
}

void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            // 不染红当前节点
            dp[u][0] += max(dp[v][0], dp[v][1]);
            // 染红当前节点
            if (isPerfectSquare(a[u] * a[v])) {
                dp[u][1] += max(dp[v][0] + 1, dp[v][1] + 1);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    int result = max(dp[1][0], dp[1][1]);
    cout << result << endl;
    
    return 0;
}

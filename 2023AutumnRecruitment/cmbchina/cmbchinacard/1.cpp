#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 10005;
const int MAXM = 25;

int N, M;
double dp[MAXM][MAXN];

int main() {
    cin >> N >> M;

    //const double PI = acos(-1.0);
    
    // 初始化 dp 数组
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;

    // 动态规划
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= j; k++) {
                if (j % k == 0) {
                    // 计算当前选第i层的情况下的表面积
                    int h = j / k;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + k * k + h * k * 2 );
                    cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                }
            }
        }
    }

    // 找到最小表面积
    double minSurface = 1e9;
    for (int i = 1; i <= N; i++) {
        minSurface = min(minSurface, dp[M][i]);
    }

    cout << static_cast<int>(round(minSurface)) << endl;
    
    return 0;
}
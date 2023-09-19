**题1**
查询子串出现了多少次，请注意，小红会询问多次。
输入描述
第一行输入两个正整数$n$和$q$，代表字符串长度和询问次数。
第二行输入一行长度为$n$的，仅由小写英文字母组成的字符串。代表小红拿到的字符串。
接下来的q行，每行输入一个仅由小写英文字母组成的字符串，代涯谛帏翟常罢艾雕撑化红的每次查询。
$1 <=n, q<= 10^5$
每次查询的字符串长度不超过 10
输出描述
输出$q$行，每行输出一个整数，代表该次查询的结果
输入
```
10 3
bobobalice
bob
alice
red
```

输出
```
2
1
0
```

**题2**
小红有两个长度为n的数组，分别为a和。她可以先选择一个实数mul，获得c数组，其中
c_i=mul*a_i+b_i，小红想知道，她能获得的数组 c，最多有几个 0。
输入：
一行一个数字n，表示数组长度。一行n个正整数a_i表示数组a。一行n个正整数b_i，表示数组b。
输出：一个正整数，表示有几个0。
示例：
输入
```
4
2 4 6 7 
1 2 3 4
```
输出
```
3
```
说明：选择mul=-0.5，则c=[0,0,0,5]，有三个0.

其中一种可能的cpp代码是：（同时为了保证精度，写一个分子分母的数据结构，支持约分（记得检验分母为0的情况），判定相等，判定小于的操作；用map<实数，int>去维护每个实数的个数）

a[i] = b[i] = 0的情况 int应该全部换成long long

**题3**
使用cpp解决这个问题：
小红拿到了3个数组，她准备各取一个前缀(前缀的长度可以是0)，总共取k个数。小红希望最终这k个数的按位或尽可能大。请你帮帮小红。
注:按位或指二进制上每一位取或运算，例如3的进制表示是(0011)，9的二进制表示是(1001)，那么
3 or 9=(1010)2=11
示例1：
输入
```
4 2 
1 2 3 4
2 2 3 4
4 2 3 4
```
输出
```
6
```
示例2
输入
```
4 4
1 2 3 4
2 2 3 4
4 2 3 4
```
输出
```
7
```

# 题解：
```cpp
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
 
using namespace std;
 
//  获取数组前 number 个数字的按位或和
int get_or(int q, int number,
           vector<vector<int>> &prefix_or) {
    return prefix_or[q][number];
}
 
//假设原数组为 1 10 1000
// prefix_or 0 1 11 1011
void calculate_prefix_or(vector<vector<int>> &array,
                         vector<vector<int>> &prefix_or) {
    for (int i = 0; i < 3; ++i) {
        prefix_or[i].resize(array[i].size() + 1);
        prefix_or[i][0] = 0;
        for (int j = 1; j <= array[i].size(); ++j) {
            prefix_or[i][j] = prefix_or[i][j - 1] | array[i][j - 1];
        }
    }
}
 
// 假设原数组为                 1 111 101 110 1000
// prefix_or                0 1 111 111 111 1111
// prefix_or_unique first   0 1 2   5
// prefix_or_unique second  0 1 111 1111
void calculate_prefix_or_unique(vector<vector<int>> &prefix_or,
                                vector<vector<pair<int, int>>> &prefix_or_unique) {
    for (int i = 0; i < 3; ++i) {
        prefix_or_unique[i].clear();
        prefix_or_unique[i].emplace_back(0, prefix_or[i][0]);
        for (int j = 0; j < prefix_or[i].size() - 1; ++j) {
            if (prefix_or[i][j] != prefix_or[i][j + 1]) {
                prefix_or_unique[i].emplace_back(j + 1, prefix_or[i][j + 1]);
            }
        }
    }
}
 
//计算答案
int calculate_ans(vector<vector<pair<int, int>>> &prefix_or_unique, int &k) {
    int ans = 0;
    for (auto &a: prefix_or_unique[0]) {
        if (a.first > k)break;
        for (auto &b: prefix_or_unique[1]) {
            if (a.first + b.first > k)break;
            for (auto &c: prefix_or_unique[2]) {
                if (a.first + b.first + c.first > k) break;
                int tmp_ans = a.second | b.second | c.second;
                ans = max(ans, tmp_ans);
            }
        }
    }
    return ans;
}
 
int solution(vector<vector<int>> &array, int &k) {
    vector<vector<int>> pref_or(3);
    calculate_prefix_or(array, pref_or);
 
    vector<vector<pair<int, int>>> uniq(3);
    calculate_prefix_or_unique(pref_or, uniq);
 
    return calculate_ans(uniq, k);
}
 
int main() {
    vector<vector<int>> array = {
            {1, 16},
            {1, 1024},
            {1, 7, 5, 6, 8},
    };
    for (int k = 0; k < 11; ++k) {
        cout << "k = " << k << ":\tans = " << solution(array, k) << endl;
    }
}
```

**题4**
用cpp解决这个问题：
小红有两个字符串s和t，每次可以对s分成s=s1+s2然后拼接成新的字符串 s2+s1。例如字符串“abcd”可以分割成“ab”和“cd”，然后拼接成"cdab"；
小红想知道恰好进行k次操作，将s变成t的方案数，输出方案数模10^9+7的结果。
注意，分割的两个字符串都不能是空串。
输入：第一行一个仅包含小写字母的字符串s，第二行一个仅包含小写字母的字符串t，第三行一个正整数k。
输出一个整数表示答案。
示例：
输入
```
abcde
cdeab
2
```
输出
```
3
```

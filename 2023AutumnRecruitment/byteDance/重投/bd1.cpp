#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 自定义分子分母数据结构
struct Fraction {
    int numerator;   // 分子
    int denominator; // 分母

    Fraction(int num, int den) {
        int gcd_val = gcd(num, den); // 计算分子和分母的最大公约数
        numerator = num / gcd_val;
        denominator = den / gcd_val;
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<Fraction, int> count_map; // 用于维护每个实数的个数

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            Fraction frac(-b[i], a[i]);
            count_map[frac]++;
        }
        if (a[i] == 0 || b[i] == 0)
        {
            Fraction frac(0, 0);
            count_map[frac]++;
        }
        
    }

    int max_zeros = 0;

    for (const auto& entry : count_map) {
        max_zeros = max(max_zeros, entry.second);
    }

    cout << max_zeros << endl;

    return 0;
}

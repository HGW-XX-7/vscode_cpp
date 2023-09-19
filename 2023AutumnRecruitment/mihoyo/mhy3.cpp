#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        // 姬子的攻击方式为: 对一个单体敌人造成2点伤害，并对与此敌人相邻的敌人各造成1点伤害。
        // 我们可以计算攻击次数，将血量最多的敌人先攻击，以尽量减少攻击次数。
        int totalAttacks = 0;
        int maxHP = max(a, max(b, c));

        // 姬子一直攻击血量最多的敌人，直到所有敌人血量都降为0或更低。
        while (maxHP > 0) {
            if (a == maxHP) {
                a -= 2; // 攻击血量最多的敌人，造成2点伤害
            } else if (b == maxHP) {
                b -= 2; // 攻击血量最多的敌人，造成2点伤害
            } else if (c == maxHP) {
                c -= 2; // 攻击血量最多的敌人，造成2点伤害
            }

            // 攻击其他敌人，造成1点伤害
            if (a > 0) {
                a--;
            }
            if (b > 0) {
                b--;
            }
            if (c > 0) {
                c--;
            }

            totalAttacks++; // 记录攻击次数
            maxHP = max(a, max(b, c)); // 更新血量最多的敌人
        }

        cout << totalAttacks << endl;
    }

    return 0;
}

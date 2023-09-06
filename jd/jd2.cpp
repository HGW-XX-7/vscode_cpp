#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // 症状的数量
    cin >> n;
    string symptoms; // 小红目前的症状
    cin >> symptoms;

    int m; // 药的数量
    cin >> m;
    vector<string> treatments(m); // 药的治疗症状
    vector<string> sideEffects(m); // 药的副作用
    for (int i = 0; i < m; i++) {
        cin >> treatments[i];
        cin >> sideEffects[i];
    }

    int q; // 小红服用的药数量
    cin >> q;
    vector<int> medicines(q);
    for (int i = 0; i < q; i++) {
        cin >> medicines[i];
    }

    for (int i = 0; i < q; i++) {
        int medicineIndex = medicines[i] - 1; // 获取小红选择的药物索引
        string treatment = treatments[medicineIndex]; // 获取要服用的药物的治疗症状
        string sideEffect = sideEffects[medicineIndex]; // 获取药物的副作用症状

        int symptomsCount = 0;
        for (int j = 0; j < n; j++) {
            if (treatment[j] == '1') {
                if (sideEffect[j] == '0' || symptoms[j] == '0') {
                    symptoms[j] = '1'; // 更新症状
                }
            }
            if (symptoms[j] == '1') {
                symptomsCount++;
            }
        }

        cout << symptomsCount << endl; // 输出当前服药后的症状数量
    }

    return 0;
}

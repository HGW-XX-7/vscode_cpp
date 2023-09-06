#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationSumDFS(const vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int start) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        // 避免重复
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue;
        }
        if (candidates[i] > target) {
            break;
        }
        current.push_back(candidates[i]);
        combinationSumDFS(candidates, target - candidates[i], current, result, i + 1);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> current;
    vector<vector<int>> result;
    combinationSumDFS(candidates, target, current, result, 0);
    return result;
}

int main() {
    vector<int> candidates ={1,2,2,5,2,6,3,3,3,4,4};
    int target = 8;

    vector<vector<int>> result = combinationSum(candidates, target);
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

int minOperationsToMaxMode(std::vector<int>& arr) {
    std::map<int, int> counter;

    // 计算每个元素的出现次数
    for (int num : arr) {
        counter[num]++;
    }

    int mode = 0, modeCount = 0;

    // 找出众数及其出现次数
    for (auto& entry : counter) {
        if (entry.second > modeCount) {
            mode = entry.first;
            modeCount = entry.second;
        }
    }

    int totalOperations = 0;

    // 遍历数组，计算操作次数
    for (int num : arr) {
        totalOperations += std::abs(num - mode);
    }

    return totalOperations;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int result = minOperationsToMaxMode(arr);
    std::cout << result << std::endl;

    return 0;
}

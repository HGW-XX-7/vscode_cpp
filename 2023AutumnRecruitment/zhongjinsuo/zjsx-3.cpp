#include <iostream>
#include <vector>

using namespace std;

bool canSum(vector<int>& nums, int k, int sum, int index) {
    if (sum == k) {
        return true;
    }
    if (sum > k || index == nums.size()) {
        return false;
    }
    return canSum(nums, k, sum + nums[index], index + 1) || canSum(nums, k, sum, index + 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 19;
    bool res = canSum(nums, k, 0, 0);
    cout << boolalpha << res << endl;
    return 0;
}
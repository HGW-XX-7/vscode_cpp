#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &nums)//打家劫舍问题
{
    int length = nums.size();
    if (length == 0)
        return 0;
    else if (length == 1)
        return nums[0];
    else
    {
        vector<int> dp(length);
        dp[0] = nums[0];//dp[i]表示前i个房子能偷到的最大金额
        dp[1] = max(nums[0], nums[1]);//dp[1]要么偷第一个房子 要么偷第二个房子
        for (int i = 2; i < length; i++)//dp[i]要么偷第i个房子 要么不偷第i个房子
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);//dp[i-2]+nums[i]表示偷第i个房子 dp[i-1]表示不偷第i个房子
        }
        return dp[length - 1];
    }
}

int main()
{
    vector<int> nums = {1, 10, 1, 1, 10, 1};
    cout << rob(nums);
    return 0;
}
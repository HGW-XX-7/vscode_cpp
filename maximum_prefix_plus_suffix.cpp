#include <iostream>
#include <vector>
using namespace std;
int maximum_prefix_plus_suffix_1(vector<int> &input_list)
{

    int sum = 0, maxq = 0, ans = 0x3f3f3f3f;;
    for(int i = 0; i<input_list.size(); ++i)//动态规划 回头细说
    {
        sum = sum + input_list[i];
        ans = min(sum - maxq, ans);
        maxq = max(sum, maxq);
    }
    return sum - ans;
}
int maximum_prefix_plus_suffix_2(vector<int> &input_list)
{
    int* left = &input_list[0];
    int* right = &input_list[input_list.size()-1];
    int max_sum = 0 , temp_sum = 0;
    while(left <= right)//双指针确实只能求局部最优 属于贪心算法
    {
        if(*left > *right)
        {
            temp_sum += *left;
            left++;
        }
        else
        {
            temp_sum += *right;
            right--;
        }
        max_sum = max(max_sum,temp_sum);
    }
    return max_sum;
}
int maximum_prefix_plus_suffix_3(vector<int> &input_list)
{
    vector<int> prefix_sum,suffix_sum;
    int temp_sum = 0;
    prefix_sum.push_back(0);
    for (auto &&i : input_list)//正序求和
    {
        temp_sum += i;
        prefix_sum.push_back(temp_sum);
    }

    temp_sum = 0;
    suffix_sum.push_back(0);
    for (int i = input_list.size()-1; i >= 0; i--)//逆序求和
    {
        temp_sum += input_list[i];
        suffix_sum.push_back(temp_sum);
    }
    
    for (int i = 0; i < suffix_sum.size(); i++)
    {
        cout<<prefix_sum[i]<<" ";
        cout<<suffix_sum[i]<<endl;
    }

    int max_sum = 0;
    for (int i = 0; i < prefix_sum.size(); i++)//遍历求最大值
    {

        for (int j = 0; j < suffix_sum.size() - i - 1; j++)
        {
            if (max_sum < prefix_sum[i] + suffix_sum[j])
            {
                max_sum = prefix_sum[i] + suffix_sum[j];
            }
        }
    }
    return max_sum;
}
int main()
{
    vector<int> input_list = {-1, 10, -1, -1, -1};
    // input_list = {-1, -1, -1, -1, -1};
    // input_list = {0, 0, 0, 0, -1};
    // input_list = {1, 1, 1, 1, 1};

    cout << maximum_prefix_plus_suffix_1(input_list) << endl;
    cout << maximum_prefix_plus_suffix_2(input_list) << endl;
    cout << maximum_prefix_plus_suffix_3(input_list) << endl;
    return 0;
}
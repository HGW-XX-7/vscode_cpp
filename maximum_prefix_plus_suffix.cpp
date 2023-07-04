#include <iostream>
#include <vector>
using namespace std;
int maximum_prefix_plus_suffix(vector<int> &input_list)
{
    int* left = &input_list[0];
    int* right = &input_list[input_list.size()-1];
    int max_sum = *left + *right , temp_sum = 0;
    while(left < right)
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

    // vector<int> prefix_sum,suffix_sum;
    // int temp_sum = 0;
    // for (auto &&i : input_list)//正序求和
    // {
    //     temp_sum += i;
    //     prefix_sum.push_back(temp_sum);
    // }

    // temp_sum = 0;
    // for (int i = input_list.size()-1; i >= 0; i--)//逆序求和
    // {
    //     temp_sum += input_list[i];
    //     suffix_sum.push_back(temp_sum);
    // }
    
    // int max_sum = prefix_sum[0] + suffix_sum[0];
    // for (int i = 0; i < input_list.size(); i++)//遍历求最大值
    // {

    //     for (int j = 0; j <= input_list.size() - i; j++)
    //     {
    //         if (max_sum < prefix_sum[i] + suffix_sum[j])
    //         {
    //             max_sum = prefix_sum[i] + suffix_sum[j];
    //         }
    //     }
    // }

    return max_sum;
}

int main()
{
    vector<int> input_list = {2,-3,4,-100,5,6,-7};
    cout << maximum_prefix_plus_suffix(input_list);
    return 0;
}
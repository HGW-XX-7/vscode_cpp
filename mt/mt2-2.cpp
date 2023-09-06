#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        temp[i] = arr[i];
    }

    if (n > 2)
    {
        sort(arr.begin(), arr.end(), greater<int>()); // 按降序排列
        long long sum = accumulate(arr.begin(), arr.end(), 0);

        for (int i = 0; i < n; i++)
        {
            if (arr[0] ==temp[i])
            {
                if (arr[1] == temp[i+1]||arr[1] == temp[i-1])
                {
                    long long maxSum = arr[0] + arr[1]; 
                    sum -= maxSum; // 去掉最大的数
                    maxSum = max(maxSum, (long long)arr[0] * arr[1]); // 尝试相乘后的和是否更大
                    cout << sum + maxSum << endl;
                    return 0;
                }
            }
        }

        cout << sum << endl;
    }
    else if (n == 2)
    {
        cout << max(arr[0] + arr[1],arr[0] * arr[1]) << endl;
    }
    else if (n == 1)
    {
        cout << arr[0] << endl;
    } 

    return 0;
}

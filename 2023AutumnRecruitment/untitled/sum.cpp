#include <iostream>
using namespace std;

bool mySum(int arr[], int n, int target, int *result1, int *result2)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] + arr[j] == target && i != j)
            {
                *result1 = arr[i];
                *result2 = arr[j];
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int target = 10, num1, num2;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (mySum(arr, n, target, &num1, &num2))
    {
        cout << num1 << " " << num2 << endl;
    }
    else
    {
        cout << "None" << endl;
    }

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int maxPerimeter(int arr[], int n) {
    sort(arr, arr + n);
    for (int i = n - 1; i >= 2; i--) {
        if (arr[i - 2] + arr[i - 1] > arr[i]) {
            return arr[i - 2] + arr[i - 1] + arr[i];
        }
    }
    return 0;
}

int main() {
    int arr[] = {2, 3, 4, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = maxPerimeter(arr, n);
    cout << res << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int maxDlete(int *arr,int len){
    int maxium = 0;
    int left = 0,right = len-1;
    if (len <= 2)
    {
        return 0;
    }
    else{
        while (left < right)
        {
            while (left < right)
            {
                if(arr[left] == arr[right]){
                maxium = max(maxium,right-left-1);
                }
                right--;
            }
            right = len-1;
            left++;
        }
        return maxium;
    }
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << maxDlete(arr,n) << endl;
    return 0;
}
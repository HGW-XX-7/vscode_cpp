#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;

bool isNeighbour(int arr[], int x, int y,int len){
    int count = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] == x || arr[i] == y) count = i;
    }
    if(arr[count] == x)
    {
        if ((arr[count - 1] == y&&count - 1 >=0)||(arr[count + 1]==y)&&count+1<len)
        {
            return true;
        }
    }
    if(arr[count] == y)
    {
        if ((arr[count-1]==x&&count-1>=0)||(arr[count+1]==x)&&count+1<len)
        {
            return true;
        }
    }
    return false;
}

int main(){
    int len;
    cin >> len;
    int arr[len];
    for(int i = 0; i < len; i++){
        cin >> arr[i];
    }
    int x,y;
    cin >> x >> y;
    if(isNeighbour(arr,x,y,len)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
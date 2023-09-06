#include <iostream>
#include <string>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int maxlen = 1;
    int num = s.length();
    int low = 0;

    if (num == 0) return 0;
    int *a;
    a = new int[num];
    a[0] = 1;
for(int i = 1; i < num; i++)
    {
        cout << "i:" << i << endl;
        for (int j = i - 1; j >= low; j--)
        {
            cout << " j:" << j << endl;
            if  (s[i] == s[j])
            {
                if(i==7)
                    cout << "  a[i - 1]=" << a[i - 1] << " a[j]=" << a[j];
                a[i] = a[i - 1] - a[j] + 1;
                low = j + 1;
                cout <<"  low="<< low << endl;
                cout <<"  i="<< i <<" a[i]="<< a[i] << endl;
                break;
            }
            else if (s[i] != s[j] && j == low)
            {
                a[i] = a[i - 1] + 1;
                cout <<"  进入else i="<< i <<" a[i]="<< a[i] <<" a[i-1]=" <<a[i-1]<< endl;
            }
        }
        maxlen = max(maxlen, a[i]);
    }
    // for (int i = 0; i < num; i++)
    // {
    //     cout << "i=" << i << " a[i]=" << a[i] << endl;
    // }
    cout << "low=" << low << " a[low]=" <<a[low]<<" s[low]="<<s[low] << endl;
    return maxlen;
}

int main()
{
    string s("bpfbhmipx");
    int length;
    
    length = lengthOfLongestSubstring(s);
    cout << "s=" << s << endl << "max length="<< length;
    
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 函数用于将字符串转换为二维vector
vector<vector<int>> StringToVector(string str)
{
    vector<vector<int>> result;
    int i = 0;
    while (i < str.size())
    {
        if (str[i] == '[')
        {
            if (str[i + 1] == '[')
            {
                i++;
                continue;
            }
            vector<int> row;
            i++;
            while (i < str.size() && str[i] != ']')
            {
                if (str[i] == ',')
                {
                    i++;
                }
                int num = 0;
                while (i < str.size() && str[i] >= '0' && str[i] <= '9')
                {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                row.push_back(num);
            }
            result.push_back(row);
        }
        else
        {
            i++;
        }
    }
    return result;
}

int main()
{
    string input;
    getline(cin, input);
    vector<vector<int>> arr = StringToVector(input);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
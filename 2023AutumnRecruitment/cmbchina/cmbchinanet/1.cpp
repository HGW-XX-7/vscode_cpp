#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isPermutation(string s1, string s2)
{
    if (s1.size() != s2.size()) {
        return false;
    }
    if (s1 != s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2;
    } else
        return false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (isPermutation(s1, s2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}

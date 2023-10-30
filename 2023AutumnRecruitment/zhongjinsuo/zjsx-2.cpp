#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getNext(string s) {
    int n = s.size();
    vector<int> next(n, 0);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}

void match(string a, string b) {
    int m = a.size();
    int n = b.size();
    vector<int> next = getNext(a);
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && b[i] != a[j]) {
            j = next[j - 1];
        }
        if (b[i] == a[j]) {
            j++;
        }
        if (j == m) {
            cout << i - m + 1 << " ";
            j = next[j - 1];
        }
    }
    cout << endl;
}

int main() {
    string a = "abc";
    string b = "ababcabcab";
    match(a, b);
    return 0;
}
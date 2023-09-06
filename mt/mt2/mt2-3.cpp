#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int total_weight = 0;
    int length = s.length();
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            string substring = s.substr(i, j - i + 1);
            int weight = 0;
            for (int k = 1; k <= substring.length(); k++) {
                if (substring[k] == substring[k - 1]) {
                    weight += 1;
                    k++;
                }
            }
            total_weight += weight;
        }
    }
    cout << total_weight << endl;
    return 0;
}

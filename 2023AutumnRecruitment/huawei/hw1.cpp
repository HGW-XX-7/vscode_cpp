#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int target_sn;
    cin >> target_sn;
    
    int start_idx = -1;
    int end_idx = -1;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] == target_sn) {
            start_idx = i;
            break;
        }
    }
    
    if (start_idx != -1) {
        for (int i = start_idx; i < n; i++) {
            if (nums[i] != target_sn) {
                end_idx = i - 1;
                break;
            }
            if (i == n - 1) {
                end_idx = i;
            }
        }
    }
    
    cout << start_idx << " " << end_idx << endl;
    
    return 0;
}

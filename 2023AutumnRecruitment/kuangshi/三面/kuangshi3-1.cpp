#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> getSkyline(TreeNode* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        int maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            maxVal = max(maxVal, node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        res.push_back(maxVal);
    }
    reverse(res.begin(), res.end());
    return res;
}

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty()) {
        return nullptr;
    }
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        int n = q.size();
        for (int j = 0; j < n; j++) {
            TreeNode* node = q.front();
            q.pop();
            if (nodes[i] != "#") {
                node->left = new TreeNode(stoi(nodes[i]));
                q.push(node->left);
            }
            i++;
            if (i >= nodes.size()) {
                break;
            }
            if (nodes[i] != "#") {
                node->right = new TreeNode(stoi(nodes[i]));
                q.push(node->right);
            }
            i++;
            if (i >= nodes.size()) {
                break;
            }
        }
    }
    return root;
}

int main() {
    string input;
    getline(cin, input);
    input = input.substr(1, input.size() - 2);
    if (input.empty()) {
        cout << "[]" << endl;
        return 0;
    }
    vector<string> nodes;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ',')) {
        nodes.push_back(token);
    }
    TreeNode* root = buildTree(nodes);
    vector<int> res = getSkyline(root);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    return 0;
}
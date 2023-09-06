#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TreeNode {
public:
    int val;
    vector<TreeNode*> children;

    TreeNode(int val) : val(val) {}
};

TreeNode* buildTree(int n, const vector<int>& edges) {
    vector<TreeNode*> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = new TreeNode(i + 1);
    }

    for (int i = 1; i < n; ++i) {
        nodes[edges[i - 1] - 1]->children.push_back(nodes[i]);
    }

    return nodes[0];
}

int dfs(TreeNode* node, unordered_map<int, int>& depthMap) {
    if (node->children.empty()) {
        depthMap[node->val] = 1;
        return 1;
    }

    int sum = 0;
    for (TreeNode* child : node->children) {
        sum += dfs(child, depthMap);
    }

    depthMap[node->val] = sum;
    return sum;
}

int main() {
    int n, Q;
    cin >> n >> Q;

    vector<int> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i];
    }

    TreeNode* root = buildTree(n, edges);
    unordered_map<int, int> depthMap;
    dfs(root, depthMap);

    int xorSumResult = 0;
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        xorSumResult ^= depthMap[a] * depthMap[b];
    }

    cout << xorSumResult << endl;

    return 0;
}

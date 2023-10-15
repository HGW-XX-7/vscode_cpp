#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

// 定义二叉树节点的结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 创建二叉树
TreeNode* createTree(const std::vector<std::string>& values) {
    if (values.empty()) {
        return nullptr;
    }

    std::queue<TreeNode*> nodes;
    TreeNode* root = new TreeNode(std::stoi(values[0]));
    nodes.push(root);

    for (size_t i = 1; i < values.size(); i += 2) {
        TreeNode* node = nodes.front();
        nodes.pop();

        if (values[i] != "#") {
            node->left = new TreeNode(std::stoi(values[i]));
            nodes.push(node->left);
        }

        if (i + 1 < values.size() && values[i + 1] != "#") {
            node->right = new TreeNode(std::stoi(values[i + 1]));
            nodes.push(node->right);
        }
    }

    return root;
}

// 从底部往上看二叉树
std::vector<int> bottomView(TreeNode* root) {
    std::vector<int> result;
    if (!root) {
        return result;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        result.push_back(q.back()->val);
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }
        }
    }

    return result;
}

int main() {
    std::string input = "{0,1,2,3,4,#,#,#,#,5,6,7,8,#,#,9,10,#,#}";
    std::replace(input.begin(), input.end(), '{', '[');
    std::replace(input.begin(), input.end(), '}', ']');

    std::vector<std::string> values;
    std::istringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ',')) {
        values.push_back(token);
    }

    TreeNode* root = createTree(values);
    std::vector<int> result = bottomView(root);

    std::cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}

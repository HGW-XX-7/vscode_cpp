#include <vector>
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return std::vector<TreeNode*>();
        }
        return generateTrees(1, n);
    }

private:
    std::vector<TreeNode*> generateTrees(int start, int end) {
        std::vector<TreeNode*> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        
        for (int i = start; i <= end; ++i) {
            std::vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1);
            std::vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end);
            
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = cloneTree(left);
                    root->right = cloneTree(right);
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
    
    TreeNode* cloneTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = cloneTree(root->left);
        newRoot->right = cloneTree(root->right);
        return newRoot;
    }
};

int main() {
    Solution solution;
    int n = 3; // 生成所有由3个节点组成的不同二叉搜索树
    std::vector<TreeNode*> result = solution.generateTrees(n);

    // 打印结果
    for (TreeNode* root : result) {
        // 这里可以编写一个函数来遍历并打印二叉树的结构
        // 可以使用中序遍历或其他遍历方式
    }

    // 释放内存
    for (TreeNode* root : result) {
        deleteTree(root);
    }

    return 0;
}

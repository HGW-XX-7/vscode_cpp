#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calculateMaxPathSum(root, maxSum);
        return maxSum;
    }
    
    int calculateMaxPathSum(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        
        // 计算左子树的最大路径和（如果为负数则不考虑）
        int leftSum = std::max(0, calculateMaxPathSum(node->left, maxSum));
        // 计算右子树的最大路径和（如果为负数则不考虑）
        int rightSum = std::max(0, calculateMaxPathSum(node->right, maxSum));
        
        // 更新全局最大路径和
        maxSum = std::max(maxSum, leftSum + rightSum + node->val);
        
        // 返回包含当前节点的最大路径和（只能选择左子树或右子树）
        return std::max(leftSum, rightSum) + node->val;
    }
};

int main() {
    TreeNode* root = new TreeNode(-20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(6);


    Solution solution;
    int maxPathSum = solution.maxPathSum(root);
    std::cout << "Maximum Path Sum: " << maxPathSum << std::endl;

    // 释放内存
    // 实际应用中，需要释放二叉树的内存
    return 0;
}

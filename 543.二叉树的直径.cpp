/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode *root) {
        // 每个节点的直径为左右子树的最大深度之和
        // 对每个节点求直径，其中最大的即为结果
        maxHeight(root);
        return res;
    }

    // 遍历求最大深度
    int maxHeight(TreeNode *root) {
        if (root == nullptr) return 0;

        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};
// @lc code=end

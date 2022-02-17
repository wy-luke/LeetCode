/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool traverse(TreeNode *root, long long max, long long min) {
        if (root == nullptr) return true;

        if (root->val <= min || root->val >= max) return false;

        return traverse(root->left, root->val, min) && traverse(root->right, max, root->val);
    }

    bool isValidBST(TreeNode *root) {
        return traverse(root, LONG_MAX, LONG_MIN);
    }
};
// @lc code=end

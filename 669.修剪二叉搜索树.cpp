/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == nullptr) return nullptr;

        TreeNode *left = trimBST(root->left, low, high);
        TreeNode *right = trimBST(root->right, low, high);

        if (root->val >= low && root->val <= high) {
            root->left = left;
            root->right = right;
            return root;
        } else {
            return left == nullptr ? right : left;
        }
    }
};
// @lc code=end

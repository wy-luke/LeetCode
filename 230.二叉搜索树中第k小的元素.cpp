/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int rank;
    int res;

public:
    void traverse(TreeNode *root) {
        if (!root) return;

        traverse(root->left);
        --rank;
        if (rank == 0) {
            res = root->val;
            return;
        }
        traverse(root->right);
    }
    int kthSmallest(TreeNode *root, int k) {
        rank = k;
        traverse(root);
        return res;
    }
};
// @lc code=end

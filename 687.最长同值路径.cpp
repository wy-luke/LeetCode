/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
private:
    int ans = 0;

public:
    int longestUnivaluePath(TreeNode *root) {
        helper(root);
        return ans;
    }

    // 返回以 当前节点 为 末尾 的最长长度
    int helper(TreeNode *root) {
        if (root == nullptr) return 0;

        int l = helper(root->left);
        int r = helper(root->right);
        int left = 0, right = 0;
        if (root->left && root->left->val == root->val) {
            left = l + 1;
        }
        if (root->right && root->right->val == root->val) {
            right = r + 1;
        }
        // 更新最大长度，可以包含左右两边
        ans = max(ans, left + right);
        // 因为是返回以 当前节点 为 末尾 的最长长度，所以只能包含一边，取最大
        // 如果当前节点和左右节点值均不同，则返回 0
        return max(left, right);
    }
};
// @lc code=end

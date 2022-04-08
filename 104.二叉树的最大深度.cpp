/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int res = 1;
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        traverse(root, 1);
        return res;
    }

    void traverse(TreeNode *root, int depth) {
        if (root->left != nullptr) {
            res = max(res, depth + 1);
            traverse(root->left, depth + 1);
        }
        if (root->right != nullptr) {
            res = max(res, depth + 1);
            traverse(root->right, depth + 1);
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode *root) {
        if (root == nullptr) return 0;

        // 计算左右子树的层数
        int lh = 1, rh = 1;
        TreeNode *lTree = root, *rTree = root;
        while (lTree->left != nullptr) {
            lTree = lTree->left;
            ++lh;
        }
        while (rTree->right != nullptr) {
            rTree = rTree->right;
            ++rh;
        }

        if (lh == rh) return (1<<lh) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end

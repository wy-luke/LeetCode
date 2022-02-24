/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
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
    void traverse(TreeNode *root) {
        if (isBST(root, INT_MAX, INT_MIN)) {
            getSum(root);
            return;
        }

        traverse(root->left);
        traverse(root->right);
    }

    bool isBST(TreeNode *root, int max, int min) {
        if (root == nullptr) return true;

        return root->val < max && root->val > min && isBST(root->left, root->val, min) && isBST(root->right, max, root->val);
    }

    int getSum(TreeNode *root) {
        if (root == nullptr) return 0;

        int sum = root->val + getSum(root->left) + getSum(root->right);
        res = max(res, sum);
        return sum;
    }

    int maxSumBST(TreeNode *root) {
        traverse(root);
        return res;
    }

private:
    int res = 0;
};
// @lc code=end

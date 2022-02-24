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
    // isBST, max, min, sum
    array<int, 4> traverse(TreeNode *root) {
        if (root == nullptr) return {1, INT_MIN, INT_MAX, 0};

        array<int, 4> left = traverse(root->left);
        array<int, 4> right = traverse(root->right);

        if (left[0] == 0 || right[0] == 0 ||
            root->val <= left[1] || root->val >= right[2]) {
            return {0, 0, 0, 0};
        } else {
            int maxValue = right[1] == INT_MIN ? root->val : right[1];
            int minValue = left[2] == INT_MAX ? root->val : left[2];
            int sum = left[3] + right[3] + root->val;
            res = max(res, sum);
            return {1, maxValue, minValue, sum};
        }
    }

    int maxSumBST(TreeNode *root) {
        traverse(root);
        return res;
    }

private:
    int res = 0;
};
// @lc code=end

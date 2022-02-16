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
public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> stk;

        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();

            --k;
            if (k == 0) break;

            root = root->right;
        }

        return root->val;
    }
};
// @lc code=end

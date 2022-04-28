/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) return {};
        bool b = false;
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> v(sz);
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front();
                q.pop();

                v[b ? sz - 1 - i : i] = node->val;

                if (node->left != nullptr) q.emplace(node->left);
                if (node->right != nullptr) q.emplace(node->right);
            }
            res.emplace_back(v);
            b = !b;
        }
        return res;
    }
};
// @lc code=end

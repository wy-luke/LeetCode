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
        deque<TreeNode *> q;
        q.emplace_back(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> v;
            v.reserve(sz);
            for (int i = 0; i < sz; ++i) {
                TreeNode *node;
                if (b) {
                    node = q.back();
                    q.pop_back();
                } else {
                    node = q.front();
                    q.pop_front();
                }

                v.emplace_back(node->val);

                if (b) {
                    if (node->right != nullptr) q.emplace_front(node->right);
                    if (node->left != nullptr) q.emplace_front(node->left);
                } else {
                    if (node->left != nullptr) q.emplace_back(node->left);
                    if (node->right != nullptr) q.emplace_back(node->right);
                }
            }
            res.emplace_back(v);
            b = !b;
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> v1, v2;
        traverse(root1, v1);
        traverse(root2, v2);
        vector<int> res;
        int p = 0, q = 0;
        int m = v1.size(), n = v2.size();
        while (p < m || q < n) {
            if (p == m) {
                res.emplace_back(v2[q++]);
            } else if (q == n) {
                res.emplace_back(v1[p++]);
            } else if (v1[p] < v2[q]) {
                res.emplace_back(v1[p++]);
            } else {
                res.emplace_back(v2[q++]);
            }
        }
        return res;
    }

    void traverse(TreeNode *root, vector<int> &v) {
        if (root == nullptr) return;

        traverse(root->left, v);
        v.emplace_back(root->val);
        traverse(root->right, v);
    }
};
// @lc code=end

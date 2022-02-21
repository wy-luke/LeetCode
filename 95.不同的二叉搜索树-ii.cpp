/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode *> generateTrees(int n) {
        memo.resize(n + 1, vector<vector<TreeNode *>>(n + 1));
        return build(1, n);
    }

    vector<TreeNode *> build(int start, int end) {
        if (end < start) return {nullptr};

        if (memo[start][end].size() != 0) return memo[start][end];

        vector<TreeNode *> res;
        for (int i = start; i <= end; ++i) {
            for (TreeNode *&m : build(start, i - 1)) {
                for (TreeNode *&n : build(i + 1, end)) {
                    TreeNode *node = new TreeNode(i);
                    node->left = m;
                    node->right = n;
                    res.emplace_back(node);
                }
            }
        }
        memo[start][end] = res;
        return res;
    }

private:
    vector<vector<vector<TreeNode *>>> memo;
};
// @lc code=end

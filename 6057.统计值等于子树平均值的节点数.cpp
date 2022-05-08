/*
 * @lc app=leetcode.cn id=6057 lang=cpp
 *
 * [6057] 统计值等于子树平均值的节点数
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
    int res = 0;
    int averageOfSubtree(TreeNode *root) {
        traverse(root);
        return res;
    }

    pair<int, int> traverse(TreeNode *root) {
        if (root == nullptr) return make_pair(0, 0);

        auto left = traverse(root->left);
        auto right = traverse(root->right);
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        if (sum / count == root->val) ++res;
        return make_pair(sum, count);
    }
};
// @lc code=end

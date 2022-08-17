/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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
    int deepestLeavesSum(TreeNode *root) {
        if (root == nullptr) return 0;

        queue<TreeNode *> qu;
        qu.emplace(root);
        int sum = 0;
        while (!qu.empty()) {
            int sz = qu.size();
            sum = 0;
            while (sz-- > 0) {
                TreeNode *node = qu.front();
                qu.pop();

                sum += node->val;
                if (node->left != nullptr) qu.emplace(node->left);
                if (node->right != nullptr) qu.emplace(node->right);
            }
        }
        return sum;
    }
};
// @lc code=end

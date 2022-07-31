/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode *root) {
        int res = 1, curLevel = 1;
        int maxSum = root->val;
        queue<TreeNode *> qu;
        qu.emplace(root);
        while (!qu.empty()) {
            int sz = qu.size(), sum = 0;
            while (sz-- > 0) {
                TreeNode *node = qu.front();
                qu.pop();
                sum += node->val;
                if (node->left != nullptr) qu.emplace(node->left);
                if (node->right != nullptr) qu.emplace(node->right);
            }
            if (sum > maxSum) {
                res = curLevel;
                maxSum = sum;
            }
            ++curLevel;
        }
        return res;
    }
};
// @lc code=end

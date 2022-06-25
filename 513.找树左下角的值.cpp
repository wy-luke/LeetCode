/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> qu;
        qu.emplace(root);
        int res;
        while (!qu.empty()) {
            int sz = qu.size();
            // 更新 res 为每行第一个元素，最后一行的第一个元素即为结果
            res = qu.front()->val;
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = qu.front();
                qu.pop();
                if (node->left != nullptr) qu.emplace(node->left);
                if (node->right != nullptr) qu.emplace(node->right);
            }
        }
        return res;
    }
};
// @lc code=end

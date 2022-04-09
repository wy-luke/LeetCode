/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode *root) {
        if (root == nullptr) return {};
        queue<TreeNode *> q;
        q.emplace(root);

        vector<int> res;
        while (!q.empty()) {
            int n = q.size();
            int maxValue = INT_MIN;
            while (n > 0) {
                TreeNode *node = q.front();
                q.pop();
                maxValue = max(maxValue, node->val);
                if (node->left != nullptr) q.emplace(node->left);
                if (node->right != nullptr) q.emplace(node->right);
                --n;
            }
            res.emplace_back(maxValue);
        }
        return res;
    }

private:
    vector<int> res;
};
// @lc code=end

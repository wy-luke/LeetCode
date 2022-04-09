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
private:
    vector<int> res;
    int depth = 0;

public:
    vector<int> largestValues(TreeNode *root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode *root) {
        if (root == nullptr) return;

        if (depth >= res.size()) {
            res.emplace_back(root->val);
        } else {
            res[depth] = max(res[depth], root->val);
        }
        depth++;
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
};
// @lc code=end

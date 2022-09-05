/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    unordered_map<string, int> mp;
    vector<TreeNode *> ans;

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        serialize(root);
        return ans;
    }

    string serialize(TreeNode *root) {
        if (root == nullptr) return "";

        string left = serialize(root->left);
        string right = serialize(root->right);

        string s = left + "#" + right + "#" + to_string(root->val);

        if (mp[s] == 1) {
            ans.emplace_back(root);
        }
        mp[s]++;
        return s;
    }
};
// @lc code=end

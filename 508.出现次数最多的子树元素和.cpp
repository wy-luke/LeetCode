/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    unordered_map<long long, int> mp;
    int maxCnt = 0;
    int traverse(TreeNode *root) {
        if (root == nullptr) return 0;
        int sum = traverse(root->left) + traverse(root->right) + root->val;
        maxCnt = max(maxCnt, ++mp[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        traverse(root);
        vector<int> res;
        for (auto const &[s, c] : mp) {
            if (c == maxCnt) res.emplace_back(s);
        }
        return res;
    }
};
// @lc code=end

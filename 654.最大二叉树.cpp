/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return helper(nums, 0, nums.size());
    }

    TreeNode *helper(vector<int> &nums, int p, int q) {
        if (p == q) return nullptr;

        int idx = max_element(nums.begin() + p, nums.begin() + q) - nums.begin();
        return new TreeNode(nums[idx], helper(nums, p, idx), helper(nums, idx + 1, q));
    }
};
// @lc code=end

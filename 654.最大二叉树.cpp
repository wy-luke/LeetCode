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
        int n = nums.size();
        // 因为最后要访问第一个元素，所以用 deque 来实现单调栈
        deque<int> stk;
        vector<TreeNode *> tree(n);
        for (int i = 0; i < n; ++i) {
            tree[i] = new TreeNode(nums[i]);
            while (!stk.empty() && nums[i] > nums[stk.back()]) {
                tree[i]->left = tree[stk.back()];
                stk.pop_back();
            }
            if (!stk.empty()) {
                tree[stk.back()]->right = tree[i];
            }
            stk.emplace_back(i);
        }
        return tree[stk.front()];
    }
};
// @lc code=end

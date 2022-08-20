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
        stack<int> stk;
        vector<int> l(n, -1), r(n, -1);
        vector<TreeNode *> trees(n);
        for (int i = 0; i < nums.size(); ++i) {
            trees[i] = new TreeNode(nums[i]);
            int num = nums[i];
            while (!stk.empty() && num > nums[stk.top()]) {
                r[stk.top()] = i;
                stk.pop();
            }
            l[i] = stk.empty() ? -1 : stk.top();
            stk.emplace(i);
        }

        TreeNode *root = nullptr;
        for (int i = 0; i < n; ++i) {
            if (l[i] == -1 && r[i] == -1) {
                root = trees[i];
            } else if (l[i] == -1 || (r[i] != -1 && nums[r[i]] < nums[l[i]])) {
                trees[r[i]]->left = trees[i];
            } else {
                trees[l[i]]->right = trees[i];
            }
        }
        return root;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode *root) {
        int ans = 1;
        vector<pair<TreeNode *, unsigned long long>> arr;
        arr.emplace_back(root, 1L);
        while (!arr.empty()) {
            ans = max(ans, int(arr.back().second - arr.front().second) + 1);

            vector<pair<TreeNode *, unsigned long long>> tmp;
            for (auto &[node, idx] : arr) {
                if (node->left != nullptr) {
                    tmp.emplace_back(node->left, idx * 2);
                }
                if (node->right != nullptr) {
                    tmp.emplace_back(node->right, idx * 2 + 1);
                }
            }
            arr = move(tmp);
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        int curDepth = 1;
        queue<TreeNode *> qu;
        qu.emplace(root);
        while (!qu.empty()) {
            int sz = qu.size();
            while (sz-- > 0) {
                TreeNode *curNode = qu.front();
                qu.pop();
                if (curDepth == depth - 1) {
                    TreeNode *a = new TreeNode(val, curNode->left, nullptr);
                    TreeNode *b = new TreeNode(val, nullptr, curNode->right);
                    curNode->left = a;
                    curNode->right = b;
                } else {
                    if (curNode->left != nullptr) qu.emplace(curNode->left);
                    if (curNode->right != nullptr) qu.emplace(curNode->right);
                }
            }
            ++curDepth;
        }
        return root;
    }
};
// @lc code=end

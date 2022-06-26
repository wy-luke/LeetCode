/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) return nullptr;
        TreeNode *parent = nullptr;
        TreeNode *node = root;
        // 找到要删除的元素
        while (node != nullptr && node->val != key) {
            parent = node;
            if (node->val < key) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        // 要删除的元素不存在
        if (node == nullptr) return root;
        // 把 node 更新为删除元素后，parent 的新后继节点
        if (node->left == nullptr && node->right == nullptr) {
            node = nullptr;
        } else if (node->left == nullptr) {
            node = node->right;
        } else if (node->right == nullptr) {
            node = node->left;
        } else {
            // 如果 node 左右均 不为 nullptr
            // 把 node->right 接在 node->left 的 右子树最底层
            TreeNode *leftParent = node;
            TreeNode *left = node->left;
            TreeNode *right = node->right;
            // 更新 node
            node = left;
            while (left != nullptr) {
                leftParent = left;
                left = left->right;
            }
            leftParent->right = right;
        }
        // parent 为 nullptr 时，说明 root 为需要删除的元素，返回 node 即可
        if (parent == nullptr) {
            return node;
        } else {
            // 更新节点
            if (parent->left != nullptr && parent->left->val == key) {
                parent->left = node;
            } else {
                parent->right = node;
            }
            return root;
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
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
    // isBST, max, min, sum
    void traverse(TreeNode *root) {
        if (root == nullptr) return;

        traverse(root->left);
        traverse(root->right);

        if (bstMemo.count(root) == 0) {
            if (!isBST(root, nullptr, nullptr)) {
                return;
            } else {
                bstMemo[root] = true;
                int sum;
                if (sumMemo.count(root) == 0) {
                    sum = getSum(root);
                    sumMemo[root] = sum;
                } else {
                    sum = sumMemo[root];
                }
                res = max(res, sum);
            }
        } else {
            if (!bstMemo[root]) {
                return;
            } else {
                bstMemo[root] = true;
                int sum;
                if (sumMemo.count(root) == 0) {
                    sum = getSum(root);
                    sumMemo[root] = sum;
                } else {
                    sum = sumMemo[root];
                }
                res = max(res, sum);
            }
        }
    }

    bool isBST(TreeNode *root, TreeNode *max, TreeNode *min) {
        if (root == nullptr) return true;

        if (max != nullptr && (root->val) >= max->val) return false;
        if (min != nullptr && (root->val) <= min->val) return false;

        return isBST(root->left, root, min) && isBST(root->right, max, root);
    }

    int getSum(TreeNode *root) {
        if (root == nullptr) return 0;

        int left = getSum(root->left);
        int right = getSum(root->right);

        return left + right + root->val;
    }

    int maxSumBST(TreeNode *root) {
        traverse(root);
        return res;
    }

private:
    int res = 0;
    unordered_map<TreeNode *, bool> bstMemo;
    unordered_map<TreeNode *, int> sumMemo;
};
// @lc code=end

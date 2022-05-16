class Solution {
private:
    int closest;
    TreeNode *res;

public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        closest = INT_MAX;
        traverse(root, p);
        return closest == INT_MAX ? nullptr : res;
    }
    // 利用 BST 树的特性遍历，找到与 p 最接近的并且大于 p 的数，即为结果
    void traverse(TreeNode *root, TreeNode *p) {
        if (root == nullptr) return;

        if (root->val > p->val && root->val < closest) {
            closest = root->val;
            res = root;
        }

        if (p->val < root->val) {
            traverse(root->left, p);
        } else {
            traverse(root->right, p);
        }
    }
};
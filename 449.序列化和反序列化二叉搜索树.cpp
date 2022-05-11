/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) return "*";

        return to_string(root->val) + "#" + serialize(root->left) + "#" + serialize(root->right);
    }
    int i = 0;
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string &data) {
        if (data[i] == '#') i++;
        if (data[i] == '*') {
            i++;
            return nullptr;
        }

        int num = 0;
        for (; i < data.size(); ++i) {
            if (data[i] == '#') break;
            num = num * 10 + data[i] - '0';
        }
        TreeNode *res = new TreeNode(num);
        res->left = deserialize(data);
        res->right = deserialize(data);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

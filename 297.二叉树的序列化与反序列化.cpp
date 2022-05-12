/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) return "*";

        return to_string(root->val) + "#" + serialize(root->left) + "#" + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int i = 0;
        return deser(data, i);
    }

    TreeNode *deser(string &data, int &i) {
        if (data[i] == '#') i++;
        if (data[i] == '*') {
            i++;
            return nullptr;
        }
        // 由于有负数，所以需要用 stoi()
        string tmp = "";
        for (; i < data.size(); ++i) {
            if (data[i] == '#') break;
            tmp += data[i];
        }

        TreeNode *res = new TreeNode(stoi(tmp));
        res->left = deser(data, i);
        res->right = deser(data, i);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

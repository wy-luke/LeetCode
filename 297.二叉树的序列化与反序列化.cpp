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
        if (root == nullptr) return "#";

        string left = serialize(root->left);
        string right = serialize(root->right);

        return left + "," + right + "," + to_string(root->val);
    }

    // #,#,2,#,#,4,#,#,5,3,1
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        vector<TreeNode *> nodes;
        string tmp;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == ',') {
                if (!tmp.empty()) nodes.push_back(new TreeNode(stoi(tmp)));
                tmp.clear();
            } else if (data[i] == '#') {
                nodes.push_back(nullptr);
            } else {
                tmp.push_back(data[i]);
                // 最后一个节点
                if (i == (data.size() - 1)) nodes.push_back(new TreeNode(stoi(tmp)));
            }
        }

        return des(nodes);
    }

    TreeNode *des(vector<TreeNode *> &nodes) {
        if (nodes.back() == nullptr) {
            nodes.pop_back();
            return nullptr;
        }

        TreeNode *root = nodes.back();
        nodes.pop_back();

        root->right = des(nodes);
        root->left = des(nodes);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

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
        if (root == nullptr) return "";

        return to_string(root->val) + "#" + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        queue<int> q;
        int num = 0;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == '#') {
                q.emplace(num);
                num = 0;
            } else {
                num = num * 10 + data[i] - '0';
            }
        }
        return deser(q, INT_MIN, INT_MAX);
    }

    TreeNode *deser(queue<int> &q, int lo, int hi) {
        if (q.empty() || q.front() < lo || q.front() > hi) return nullptr;
        int num = q.front();
        q.pop();
        TreeNode *res = new TreeNode(num);
        res->left = deser(q, lo, num);
        res->right = deser(q, num, hi);
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

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    // 通过 位运算 判断标号为 target 的节点是否存在
    bool check(TreeNode *root, int target, int h) {
        int bit = 1 << (h - 1);
        while (bit != 0) {
            // 位运算比较原理见下
            if ((target & bit) == 0) {
                root = root->left;
            } else {
                root = root->right;
            }
            if (root == nullptr) return false;
            // 要用 >>= !!!
            bit >>= 1;
        }
        return true;
    }
    int countNodes(TreeNode *root) {
        // 防止访问 null
        if (root == nullptr) return 0;
        // check 函数中有 1<<(h-1)，则 h-1 需大于等于 0，即 h>=1，排除 h=0
        if (root->left == nullptr) return 1;
        // 规定层数 h 从 0 开始
        int h = -1;
        TreeNode *node = root;
        while (node != nullptr) {
            ++h;
            node = node->left;
        }
        // 第 h 层，即最后一层，的节点标号从 2^h，到 2^(h+1)-1
        int l = 1 << h, r = (1 << (h + 1)) - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(root, mid, h)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};
// 位运算解释
//     1            h = 0
//    / \
//   2   3          h = 1
//  / \  /
// 4  5 6           h = 2
// 现在这个树中的值都是节点的编号，最底下的一层的编号是[2^h ，2^h - 1]，现在h = 2，也就是4, 5, 6, 7
// 4, 5, 6, 7对应二进制分别为 100 101 110 111 不看最左边的1，从第二位开始，0表示向左，1表示向右，正好可以表示这个节点相对于根节点的位置
// 比如4的 00 就表示从根节点 向左 再向左。6的 10 就表示从根节点 向右 再向左

// 那么想访问最后一层的节点就可以从节点的编号的二进制入手。从第二位开始的二进制位表示了最后一层的节点相对于根节点的位置。
// 那么就需要一个bits = 2^(h - 1) 上面例子中的bits就是2，对应二进制为010。这样就可以从第二位开始判断。（树三层高，需要向左或向右走两次才能到叶子）
// 比如看5这个节点存不存在，先通过位运算找到编号为5的节点相对于根节点的位置。010 & 101 发现第二位是0，说明从根节点开始，第一步向左走。
// 之后将bit右移一位，变成001。001 & 101 发现第三位是1，那么第二步向右走
// 最后bit为0，说明已经找到编号为5的这个节点相对于根节点的位置，看这个节点是不是空，不是说明存在，exist返回真
// 编号为5的节点存在，说明总节点数量一定大于等于5。所以二分那里low = mid

// 再比如看7存不存在，010 & 111 第二位为1，第一部从根节点向右；001 & 111 第三位也为1，第二步继续向右
// 然后判断当前节点是不是null，发现是null，exist返回假。
// 编号为7的节点不存在，说明总节点数量一定小于7。所以high = mid - 1
// @lc code=end

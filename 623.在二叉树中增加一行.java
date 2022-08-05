/*
 * @lc app=leetcode.cn id=623 lang=java
 *
 * [623] 在二叉树中增加一行
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, null);
        }
        int curDepth = 1;
        Deque<TreeNode> dq = new ArrayDeque<>();
        dq.addLast(root);
        while (!dq.isEmpty()) {
            int sz = dq.size();
            while (sz-- > 0) {
                TreeNode cur = dq.pollFirst();
                if (curDepth == depth - 1) {
                    TreeNode a = new TreeNode(val, cur.left, null);
                    TreeNode b = new TreeNode(val, null, cur.right);
                    cur.left = a;
                    cur.right = b;
                } else {
                    if (cur.left != null)
                        dq.addLast(cur.left);
                    if (cur.right != null)
                        dq.addLast(cur.right);
                }
            }
            ++curDepth;
        }
        return root;
    }
}
// @lc code=end

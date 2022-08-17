/*
 * @lc app=leetcode.cn id=1302 lang=java
 *
 * [1302] 层数最深叶子节点的和
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
    private int maxLevel = 0;
    private int sum = 0;

    public int deepestLeavesSum(TreeNode root) {
        dfs(root, 1);
        return sum;
    }

    public void dfs(TreeNode root, int level) {
        if (root == null) {
            return;
        }

        if (level > maxLevel) {
            maxLevel = level;
            sum = root.val;
        } else if (level == maxLevel) {
            sum += root.val;
        }

        dfs(root.left, level + 1);
        dfs(root.right, level + 1);
    }
}
// @lc code=end

import java.util.ArrayDeque;
import java.util.Deque;

/*
 * @lc app=leetcode.cn id=1161 lang=java
 *
 * [1161] 最大层内元素和
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
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public int maxLevelSum(TreeNode root) {
        int res = 1, curLevel = 1;
        int maxSum = root.val;
        Deque<TreeNode> qu = new ArrayDeque<>();
        qu.addLast(root);
        while (!qu.isEmpty()) {
            int sz = qu.size(), sum = 0;
            while (sz-- > 0) {
                TreeNode node = qu.pollFirst();
                sum += node.val;
                if (node.left != null) {
                    qu.addLast(node.left);
                }
                if (node.right != null) {
                    qu.addLast(node.right);
                }
            }
            if (sum > maxSum) {
                res = curLevel;
                maxSum = sum;
            }
            ++curLevel;
        }
        return res;
    }
}
// @lc code=end

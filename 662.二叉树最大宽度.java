import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=662 lang=java
 *
 * [662] 二叉树最大宽度
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
    public int widthOfBinaryTree(TreeNode root) {
        int ans = 1;
        List<Pair<TreeNode, Integer>> arr = new ArrayList<>();
        arr.add(new Pair<TreeNode, Integer>(root, 1));
        while (!arr.isEmpty()) {
            ans = Math.max(ans, arr.get(arr.size() - 1).getValue() - arr.get(0).getValue() + 1);
            List<Pair<TreeNode, Integer>> tmp = new ArrayList<>();
            for (Pair<TreeNode, Integer> pair : arr) {
                TreeNode node = pair.getKey();
                int index = pair.getValue();
                if (node.left != null) {
                    tmp.add(new Pair<TreeNode, Integer>(node.left, index * 2));
                }
                if (node.right != null) {
                    tmp.add(new Pair<TreeNode, Integer>(node.right, index * 2 + 1));
                }
            }
            arr = tmp;
        }
        return ans;
    }
}
// @lc code=end

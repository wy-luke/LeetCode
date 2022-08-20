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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        int n = nums.length;
        Deque<Integer> dq = new ArrayDeque<>();
        TreeNode[] tree = new TreeNode[n];
        for (int i = 0; i < n; ++i) {
            tree[i] = new TreeNode(nums[i]);
            while (!dq.isEmpty() && nums[i] > nums[dq.peekLast()]) {
                tree[i].left = tree[dq.pollLast()];
            }
            if (!dq.isEmpty()) {
                tree[dq.peekLast()].right = tree[i];
            }
            dq.addLast(i);
        }
        return tree[dq.peekFirst()];
    }
}
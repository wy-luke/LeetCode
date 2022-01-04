/*
 * @lc app=leetcode.cn id=114 lang=csharp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    public void Flatten(TreeNode root)
    {
        if (root == null) return;

        Flatten(root.left);
        Flatten(root.right);

        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;

        TreeNode r = root;
        while (r.right != null)
        {
            r = r.right;
        }
        r.right = root.left;
        root.left = null;
    }
}
// @lc code=end


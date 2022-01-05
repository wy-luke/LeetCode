/*
 * @lc app=leetcode.cn id=104 lang=csharp
 *
 * [104] 二叉树的最大深度
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
    // 分解问题解法
    public int MaxDepth2(TreeNode root)
    {
        if (root == null) return 0;

        int maxLeft = MaxDepth(root.left);
        int maxRight = MaxDepth(root.right);

        return Math.Max(maxLeft, maxRight) + 1;
    }

    // 遍历解法
    int res = 0;
    int maxDepth = 0;
    public int MaxDepth(TreeNode root)
    {
        Traverse(root);
        return res;
    }

    public void Traverse(TreeNode root)
    {
        if (root == null)
        {
            res = Math.Max(res, maxDepth);
            return;
        }

        ++maxDepth;
        Traverse(root.left);
        Traverse(root.right);
        --maxDepth;
    }
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=106 lang=csharp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    public TreeNode BuildTree(int[] inorder, int[] postorder)
    {
        return Build(inorder, 0, inorder.Length - 1, postorder, 0, postorder.Length - 1);
    }

    public TreeNode Build(int[] inorder, int inStart, int inEnd, int[] postorder, int postStart, int postEnd)
    {
        if (postStart > postEnd) return null;

        int rootIndex = -1;
        int rootValue = postorder[postEnd];
        for (int i = inStart; i <= inEnd; ++i)
        {
            if (inorder[i] == rootValue)
            {
                rootIndex = i;
                break;
            }
        }
        TreeNode root = new TreeNode(rootValue);

        int leftSize = rootIndex - inStart;
        root.left = Build(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftSize - 1);
        root.right = Build(inorder, rootIndex + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);

        return root;
    }
}
// @lc code=end


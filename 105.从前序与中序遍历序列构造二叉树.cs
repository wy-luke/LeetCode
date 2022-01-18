/*
 * @lc app=leetcode.cn id=105 lang=csharp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    public TreeNode BuildTree(int[] preorder, int[] inorder)
    {
        return Build(preorder, 0, preorder.Length - 1, inorder, 0, inorder.Length - 1);
    }

    public TreeNode Build(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd)
    {
        if (preStart > preEnd) return null;

        int rootIndex = -1;
        int rootValue = preorder[preStart];
        for (int i = inStart; i <= inEnd; ++i)
        {
            if (inorder[i] == rootValue)
            {
                rootIndex = i;
            }
        }
        TreeNode root = new TreeNode(rootValue);

        int leftSize = rootIndex - inStart;
        root.left = Build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, rootIndex - 1);
        root.right = Build(preorder, preStart + leftSize + 1, preEnd, inorder, rootIndex + 1, inEnd);

        return root;
    }
}
// @lc code=end


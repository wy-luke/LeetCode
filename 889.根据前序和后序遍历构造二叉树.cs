/*
 * @lc app=leetcode.cn id=889 lang=csharp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    public TreeNode ConstructFromPrePost(int[] preorder, int[] postorder)
    {
        return Build(preorder, 0, preorder.Length - 1, postorder, 0, postorder.Length - 1);
    }

    public TreeNode Build(int[] preorder, int preStart, int preEnd, int[] postorder, int postStart, int postEnd)
    {
        if (preStart > preEnd) return null;

        if (preStart == preEnd) return new TreeNode(preorder[preStart]);

        int leftRootIndex = -1;
        int leftRootValue = preorder[preStart + 1];
        for (int i = postStart; i < postEnd; ++i)
        {
            if (postorder[i] == leftRootValue)
            {
                leftRootIndex = i;
                break;
            }
        }
        TreeNode root = new TreeNode(preorder[preStart]);

        int leftSize = leftRootIndex - postStart + 1;
        root.left = Build(preorder, preStart + 1, preStart + leftSize, postorder, postStart, leftRootIndex);
        root.right = Build(preorder, preStart + leftSize + 1, preEnd, postorder, leftRootIndex + 1, postEnd - 1);

        return root;
    }
}
// @lc code=end


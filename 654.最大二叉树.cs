/*
 * @lc app=leetcode.cn id=654 lang=csharp
 *
 * [654] 最大二叉树
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
    public TreeNode ConstructMaximumBinaryTree(int[] nums)
    {
        if (nums.Length == 0) return null;

        return MaximumBinaryTree(nums, 0, nums.Length - 1);
    }

    public TreeNode MaximumBinaryTree(int[] nums, int left, int right)
    {
        if (left > right) return null;

        int maxValue = Int32.MinValue;
        int maxIndex = -1;
        for (int i = left; i < right + 1; ++i)
        {
            if (nums[i] > maxValue)
            {
                maxValue = nums[i];
                maxIndex = i;
            }
        }

        TreeNode root = new TreeNode(maxValue);
        root.left = MaximumBinaryTree(nums, left, maxIndex - 1);
        root.right = MaximumBinaryTree(nums, maxIndex + 1, right);

        return root;
    }
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=652 lang=csharp
 *
 * [652] 寻找重复的子树
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
    public IList<TreeNode> FindDuplicateSubtrees(TreeNode root)
    {
        Traverse(root);
        return res;
    }

    Dictionary<string, int> memo = new Dictionary<string, int>();
    List<TreeNode> res = new List<TreeNode>();
    public string Traverse(TreeNode root)
    {
        if (root == null) return "#";

        string left = Traverse(root.left);
        string right = Traverse(root.right);

        string subTree = left + "," + right + "," + root.val;

        if (memo.TryGetValue(subTree, out int freq))
        {
            if (freq == 1)
            {
                res.Add(root);
            }
            ++memo[subTree];
        }
        else
        {
            memo.Add(subTree, 1);
        }

        return subTree;
    }
}
// @lc code=end


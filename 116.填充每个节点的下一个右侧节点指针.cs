/*
 * @lc app=leetcode.cn id=116 lang=csharp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
}
*/

public class Solution
{
    public Node Connect(Node root)
    {
        if (root == null) return null;

        ConnectTwo(root.left, root.right);

        return root;
    }

    public void ConnectTwo(Node n1, Node n2)
    {
        if (n1 == null) return;

        n1.next = n2;

        ConnectTwo(n1.left, n1.right);
        ConnectTwo(n2.left, n2.right);
        ConnectTwo(n1.right, n2.left);
    }
}
// @lc code=end


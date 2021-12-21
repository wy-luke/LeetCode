/*
 * @lc app=leetcode.cn id=19 lang=csharp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
    public ListNode RemoveNthFromEnd(ListNode head, int n)
    {
        ListNode node0 = new ListNode(0, head);
        ListNode node1 = node0;
        ListNode node2 = node0;

        while (n >= 0)
        {
            node2 = node2.next;
            n--;
        }

        while (node2 != null)
        {
            node1 = node1.next;
            node2 = node2.next;
        }

        node1.next = node1.next.next;
        return node0.next;
    }
}
// @lc code=end


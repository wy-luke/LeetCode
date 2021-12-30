/*
 * @lc app=leetcode.cn id=92 lang=csharp
 *
 * [92] 反转链表 II
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
    public ListNode ReverseBetween(ListNode head, int left, int right)
    {
        if (left == 1) return ReverseFirstN(head, right);

        head.next = ReverseBetween(head.next, --left, --right);
        return head;
    }
    
    ListNode s = null;
    public ListNode ReverseFirstN(ListNode head, int n)
    {
        if (n == 1)
        {
            s = head.next;
            return head;
        }

        ListNode last = ReverseFirstN(head.next, n - 1);
        head.next.next = head;
        head.next = s;

        return last;
    }
}
// @lc code=end


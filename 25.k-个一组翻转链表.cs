/*
 * @lc app=leetcode.cn id=25 lang=csharp
 *
 * [25] K 个一组翻转链表
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
    public ListNode ReverseKGroup(ListNode head, int k)
    {
        ListNode a, b;
        a = b = head;
        for (int i = 0; i < k; ++i)
        {
            if (b == null) return head;
            b = b.next;
        }

        ListNode newHead = Reverse(a, b);
        a.next = ReverseKGroup(b, k);
        return newHead;
    }

    public ListNode Reverse(ListNode a, ListNode b)
    {
        ListNode pre, cur, nxt;
        pre = null; cur = nxt = a;
        while (cur != b)
        {
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
}
// @lc code=end


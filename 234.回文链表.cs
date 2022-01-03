/*
 * @lc app=leetcode.cn id=234 lang=csharp
 *
 * [234] 回文链表
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
    public bool IsPalindrome(ListNode head)
    {
        ListNode slow, fast;
        slow = fast = head;

        Stack<ListNode> stack = new Stack<ListNode>();

        while (fast != null && fast.next != null)
        {
            stack.Push(slow);
            slow = slow.next;
            fast = fast.next.next;
        }

        if (fast != null) slow = slow.next;

        while (slow != null)
        {
            if (slow.val != stack.Pop().val) return false;
            slow = slow.next;
        }
        return true;
    }
}
// @lc code=end


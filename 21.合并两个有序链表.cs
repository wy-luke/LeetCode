/*
 * @lc app=leetcode.cn id=21 lang=csharp
 *
 * [21] 合并两个有序链表
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
    public ListNode MergeTwoLists(ListNode l1, ListNode l2)
    {
        ListNode result = new ListNode();
        ListNode result0 = result;

        while (l1 != null && l2 != null)
        {
            if (l2.val <= l1.val)
            {
                result = result.next = l2;
                l2 = l2.next;
            }
            else
            {
                result = result.next = l1;
                l1 = l1.next;
            }
        }

        result.next = l1 == null ? l2 : l1;
        return result0.next;
    }
}
// @lc code=end


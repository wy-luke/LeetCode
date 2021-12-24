/*
 * @lc app=leetcode.cn id=23 lang=csharp
 *
 * [23] 合并K个升序链表
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
    public ListNode MergeKLists(ListNode[] lists)
    {
        ListNode dummy = new ListNode();
        ListNode p = dummy;

        int k = lists.Length;
        for (int i = 0; i < k; ++i)
        {
            if(i == 0) int min = lists[i]
        }
    }
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1 = head, *p2 = head;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy;
        while (n > 0) {
            p2 = p2->next;
            n--;
        }
        while (p2 != nullptr) {
            p2 = p2->next;
            pre = p1;
            p1 = p1->next;
        }
        pre->next = p1->next;
        return dummy->next;
    }
};
// @lc code=end

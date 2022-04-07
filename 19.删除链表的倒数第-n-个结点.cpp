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
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p1 = dummy, *p2 = dummy;
        // 直接找倒数第 n+1 个，省去 pre 变量记录前一个节点
        while (n >= 0) {
            p2 = p2->next;
            n--;
        }
        while (p2 != nullptr) {
            p2 = p2->next;
            p1 = p1->next;
        }
        p1->next = p1->next->next;
        return dummy->next;
    }
};
// @lc code=end

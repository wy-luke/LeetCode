/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while (p1->next != nullptr) {
            p1 = p1->next;
        }
        ListNode *tmp = p1;
        p1->next = p2;

        p1 = p2 = headA;
        while (p2 != nullptr && p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;

            if (p1 == p2) {
                p1 = headA;
                while (p1 != p2) {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                tmp->next = nullptr;
                return p1;
            }
        }
        tmp->next = nullptr;
        return nullptr;
    }
};
// @lc code=end

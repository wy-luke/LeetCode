// @before-stub-for-debug-begin
#include "commoncppproblem148.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode *sortList(ListNode *head) {
        // 递归的 base case 为 head->next == nullptr 在此之前还需 head != nullptr
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *mid = findMid(head); // 找中间节点
        ListNode *rightHead = mid->next;
        mid->next = nullptr; // 断链！！！
        return merge(sortList(head), sortList(rightHead));
    }

    ListNode *findMid(ListNode *head) {
        ListNode *p1 = head, *p2 = head->next;
        while (p2 != nullptr && p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }

    // 即合并两个有序链表
    ListNode *merge(ListNode *l, ListNode *r) {
        ListNode *dummy = new ListNode(-1); // 记得 new 初始化！！！！
        ListNode *p = dummy;
        while (l != nullptr && r != nullptr) {
            if (l->val > r->val) {
                p->next = r;
                r = r->next;
            } else {
                p->next = l;
                l = l->next;
            }
            p = p->next;
        }
        p->next = l == nullptr ? r : l;
        return dummy->next;
    }
};
// @lc code=end

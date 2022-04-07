/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;

        auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

        for (auto i : lists) {
            if (i == nullptr) continue;
            pq.emplace(i);
        }

        ListNode *dummy = new ListNode();
        ListNode *p = dummy;

        while (!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            p->next = node;
            if (node->next != nullptr) {
                pq.emplace(node->next);
            }
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end

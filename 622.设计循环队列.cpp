/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(-1), next(nullptr) {}
        ListNode(int v, ListNode *n) : val(v), next(n) {}
    };
    int len, cnt;
    ListNode *head, *tail;

public:
    MyCircularQueue(int k) {
        len = k;
        cnt = 0;
        head = new ListNode();
        tail = head;
    }

    bool enQueue(int value) {
        if (cnt == len) return false;

        ListNode *node = new ListNode(value, nullptr);
        tail->next = node;
        tail = node;
        ++cnt;
        return true;
    }

    bool deQueue() {
        if (head->next == nullptr) return false;
        head->next = head->next->next;
        --cnt;
        if (cnt == 0) tail = head;
        return true;
    }

    int Front() {
        if (head->next == nullptr) return -1;
        return head->next->val;
    }

    int Rear() {
        if (head->next == nullptr) return -1;
        return tail->val;
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == len;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

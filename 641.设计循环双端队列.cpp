/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
struct DeListNode {
    DeListNode *pre, *next;
    int val;
    DeListNode(int value) : val(value), pre(nullptr), next(nullptr) {}
    DeListNode(int value, DeListNode *_pre, DeListNode *_next) : val(value), pre(_pre), next(_next) {}
};

class MyCircularDeque {
public:
    DeListNode *head = new DeListNode(-1);
    DeListNode *tail = head;
    int size, capacity;
    MyCircularDeque(int k) {
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (size >= capacity) return false;
        DeListNode *node = new DeListNode(value, head, head->next);
        if (head->next == nullptr) {
            tail = node;
        } else {
            head->next->pre = node;
        }
        head->next = node;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (size >= capacity) return false;
        DeListNode *node = new DeListNode(value, tail, nullptr);
        tail->next = node;
        tail = node;
        size++;
        return true;
    }

    bool deleteFront() {
        if (size == 0) return false;
        DeListNode *node = head->next;
        head->next = head->next->next;
        if (head->next == nullptr) {
            tail = head;
        } else {
            head->next->pre = head;
            delete node;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (size == 0) return false;
        DeListNode *node = tail;
        tail = tail->pre;
        tail->next = nullptr;
        delete node;
        size--;
        return true;
    }

    int getFront() {
        if (size == 0) return -1;
        return head->next->val;
    }

    int getRear() {
        if (size == 0) return -1;
        return tail->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

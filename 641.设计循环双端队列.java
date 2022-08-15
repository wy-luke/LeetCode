/*
 * @lc app=leetcode.cn id=641 lang=java
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
    private class DeListNode {
        DeListNode pre, next;
        int val;

        DeListNode(int value) {
            val = value;
        }

        DeListNode(int value, DeListNode _pre, DeListNode _next) {
            val = value;
            pre = _pre;
            next = _next;
        }
    };

    DeListNode head = new DeListNode(-1);
    DeListNode tail = head;
    int size, capacity;

    public MyCircularDeque(int k) {
        size = 0;
        capacity = k;
    }

    public boolean insertFront(int value) {
        if (size >= capacity) {
            return false;
        }

        DeListNode node = new DeListNode(value, head, head.next);
        if (head.next == null) {
            tail = node;
        } else {
            head.next.pre = node;
        }
        head.next = node;
        size++;
        return true;
    }

    public boolean insertLast(int value) {
        if (size >= capacity) {
            return false;
        }

        DeListNode node = new DeListNode(value, tail, null);
        tail.next = node;
        tail = node;
        size++;
        return true;
    }

    public boolean deleteFront() {
        if (size == 0) {
            return false;
        }

        head.next = head.next.next;
        if (head.next == null) {
            tail = head;
        } else {
            head.next.pre = head;
        }
        size--;
        return true;
    }

    public boolean deleteLast() {
        if (size == 0) {
            return false;
        }

        tail = tail.pre;
        tail.next = null;

        size--;
        return true;
    }

    public int getFront() {
        if (size == 0) {
            return -1;
        }
        return head.next.val;
    }

    public int getRear() {
        if (size == 0) {
            return -1;
        }

        return tail.val;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
// @lc code=end

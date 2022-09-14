/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    stack<int> stk1, stk2;

public:
    MyQueue() {
    }

    void push(int x) {
        stk1.emplace(x);
    }

    int pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.emplace(stk1.top());
                stk1.pop();
            }
        }
        int num = stk2.top();
        stk2.pop();
        return num;
    }

    int peek() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.emplace(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }

    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

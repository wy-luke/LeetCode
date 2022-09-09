import java.util.ArrayDeque;
import java.util.Deque;

/*
 * @lc app=leetcode.cn id=232 lang=java
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
    private Deque<Integer> stk1 = new ArrayDeque<>();
    private Deque<Integer> stk2 = new ArrayDeque<>();

    public MyQueue() {

    }

    public void push(int x) {
        stk1.addLast(x);
    }

    public int pop() {
        if (stk2.isEmpty()) {
            while (!stk1.isEmpty()) {
                stk2.addLast(stk1.pollLast());
            }
        }
        return stk2.pollLast();
    }

    public int peek() {
        if (stk2.isEmpty()) {
            while (!stk1.isEmpty()) {
                stk2.addLast(stk1.pollLast());
            }
        }
        return stk2.peekLast();

    }

    public boolean empty() {
        return stk1.isEmpty() && stk2.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
// @lc code=end

import java.util.ArrayDeque;
import java.util.Deque;

/*
 * @lc app=leetcode.cn id=946 lang=java
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int n = pushed.length;
        Deque<Integer> st = new ArrayDeque<>();
        for (int i = 0, j = 0; i < n; ++i) {
            st.addLast(pushed[i]);
            while (!st.isEmpty() && st.peekLast() == popped[j]) {
                st.pollLast();
                ++j;
            }
        }
        return st.isEmpty();
    }
}
// @lc code=end

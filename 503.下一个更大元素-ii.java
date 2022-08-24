import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

/*
 * @lc app=leetcode.cn id=503 lang=java
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        Arrays.fill(res, -1);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < 2 * n; ++i) {
            while (!stk.isEmpty() && nums[stk.peekLast()] < nums[i % n]) {
                res[stk.pollLast()] = nums[i % n];
            }
            stk.addLast(i % n);
        }
        return res;
    }
}
// @lc code=end

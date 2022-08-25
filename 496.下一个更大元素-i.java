import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=496 lang=java
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> stk = new ArrayDeque<>();
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = nums2.length - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums2[i] > stk.peekLast()) {
                stk.pollLast();
            }
            mp.put(nums2[i], stk.isEmpty() ? -1 : stk.peekLast());
            stk.addLast(nums2[i]);
        }
        for (int i = 0; i < nums1.length; ++i) {
            nums1[i] = mp.get(nums1[i]);
        }
        return nums1;
    }
}
// @lc code=end

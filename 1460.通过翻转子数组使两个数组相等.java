import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1460 lang=java
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        Arrays.sort(target);
        Arrays.sort(arr);
        return Arrays.equals(target, arr);
    }
}
// @lc code=end

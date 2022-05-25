/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if ((long long)mid * mid <= x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};
// @lc code=end

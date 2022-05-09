/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        int p = 1, q = 2;
        for (int i = 3; i <= n; ++i) {
            int sum = p + q;
            p = q;
            q = sum;
        }
        return q;
    }
};
// @lc code=end

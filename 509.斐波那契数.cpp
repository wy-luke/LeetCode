/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int prev = 0, curr = 1;

        for (int i = 2; i <= n; ++i) {
            int sum = prev + curr;
            prev = curr;
            curr = sum;
        }
        return curr;
    }
};
// @lc code=end

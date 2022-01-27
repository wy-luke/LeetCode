/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> memo;
    int fib(int n) {
        if (n == 0 || n == 1) return n;

        if (memo.count(n) != 0) return memo[n];

        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    }
};
// @lc code=end

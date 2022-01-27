/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
private:
    unordered_map<int, int> memo;

public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        if (memo.count(n) == 0)
        {
            memo[n] = fib(n - 1) + fib(n - 2);
            return memo[n];
        }
        else
        {
            return memo[n];
        }
    }
};
// @lc code=end

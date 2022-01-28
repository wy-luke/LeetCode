/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> memo;
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) return 0;

        if (amount < 0) return -1;

        if (memo.count(amount) != 0) {
            return memo[amount];
        }

        int res = INT_MAX;
        for (int coin : coins) {
            int subProblem = coinChange(coins, amount - coin);

            if (subProblem == -1) continue;

            res = min(res, subProblem + 1);
        }

        memo[amount] = res == INT_MAX ? -1 : res;

        return memo[amount];
    }
};
// @lc code=end

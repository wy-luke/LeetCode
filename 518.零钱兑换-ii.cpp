/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        // 原 dp[i][j] 对前 i 个硬币，容量为 j 时，能够恰好装满的方案数
        // 状态压缩
        vector<int> dp(amount + 1);
        // base case: dp[0][...] 为 0(默认)，dp[...][0] 为 1
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j - coins[i] >= 0) {
                    dp[j] = dp[j] + dp[j - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};
// @lc code=end

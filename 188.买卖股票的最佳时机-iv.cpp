/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (k == 0 || n == 0) return 0;
        // 每天都进行交易，即一天买入一天卖出，最大交易数为 n/2 ，再大也失去了限制
        if (k > n / 2) k = n / 2;
        // 压缩后的 dp
        vector<vector<int>> dp(k + 1, vector<int>(2));
        // base case 即第一天的情况
        for (int i = 0; i <= k; ++i) {
            dp[i][0] = 0;
            dp[i][1] = -prices[0];
        }
        // 从第二天到最后一天
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = k; j >= 1; --j) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
            }
        }
        return dp[k][0];
    }
};
// @lc code=end

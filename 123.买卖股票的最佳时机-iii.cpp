/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int dp_20 = 0, dp_21 = -prices[0], dp_10 = 0, dp_11 = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp_20 = max(dp_20, dp_21 + prices[i]);
            dp_21 = max(dp_21, dp_10 - prices[i]);
            dp_10 = max(dp_10, dp_11 + prices[i]);
            dp_11 = max(dp_11, -prices[i]);
        }
        return dp_20;
    }
};
// @lc code=end

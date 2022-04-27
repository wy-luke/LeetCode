/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int dp_0 = 0, dp_1 = -prices[0];
        for (int i = 2; i <= prices.size(); ++i) {
            dp_0 = max(dp_1 + prices[i - 1], dp_0);
            dp_1 = max(dp_1, -prices[i - 1]);
        }
        return dp_0;
    }
};
// @lc code=end

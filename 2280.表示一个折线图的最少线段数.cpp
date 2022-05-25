/*
 * @lc app=leetcode.cn id=2280 lang=cpp
 *
 * [2280] 表示一个折线图的最少线段数
 */

// @lc code=start
class Solution {
public:
    int minimumLines(vector<vector<int>> &stockPrices) {
        sort(stockPrices.begin(), stockPrices.end());
        int n = stockPrices.size();
        int res = 0;
        // 精度问题，使用 long double，同时也可以使用 乘法，避免精度问题
        long double pre = 2e9;
        for (int i = 1; i < n; ++i) {
            long double k = (long double)(stockPrices[i][1] - stockPrices[i - 1][1]) / (stockPrices[i][0] - stockPrices[i - 1][0]);
            if (k != pre) {
                ++res;
                pre = k;
            }
        }
        return res;
    }
};
// @lc code=end

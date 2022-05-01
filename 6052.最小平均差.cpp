/*
 * @lc app=leetcode.cn id=6052 lang=cpp
 *
 * [6052] 最小平均差
 */

// @lc code=start
class Solution {
public:
    int minimumAverageDifference(vector<int> &nums) {
        int n = nums.size();
        // 前缀和记得用 long long ！！！
        vector<long long> preSum(n + 1);
        preSum[0] = 0;
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        long long minVal = LLONG_MAX;
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            long long tmp = abs((preSum[i + 1] - preSum[0]) / (i + 1) - (preSum[n] - preSum[i + 1]) / (n - i - 1));
            if (tmp < minVal) {
                minVal = tmp;
                res = i;
            }
        }
        return minVal > preSum[n] / n ? n - 1 : res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2270 lang=cpp
 *
 * [2270] 分割数组的方案数
 */

// @lc code=start
class Solution {
public:
    int waysToSplitArray(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        // 记得前缀和用 long long
        vector<long long> pre(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (pre[i + 1] >= pre[n] - pre[i + 1]) ++res;
        }
        return res;
    }
};
// @lc code=end

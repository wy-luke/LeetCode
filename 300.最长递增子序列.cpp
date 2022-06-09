/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        // dp[k] 为所有长度为 k 的增长子序列的最小结尾
        vector<int> dp;
        dp.emplace_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            // 更新策略：
            // 如果 nums[i] 大于 dp 最后一个值，则把 nums[i] 加入 dp，即 res+1
            // 如果小于，则更新 dp，找到第一个大于 nums[i] 的位置 k，更新为 nums[i]
            // 意思是现在 长度为 k 的增长子序列的最小结尾为 nums[i]
            // 等于时，替换等于的数即可
            if (nums[i] > dp.back()) {
                dp.emplace_back(nums[i]);
            } else {
                // int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                int l = 0, r = dp.size();
                while (l < r) {
                    int mid = l + ((r - l) >> 1);
                    if (dp[mid] < nums[i]) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                dp[l] = nums[i];
            }
        }
        return dp.size();
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1800 lang=cpp
 *
 * [1800] 最大升序子数组和
 */

// @lc code=start
class Solution {
public:
    int maxAscendingSum(vector<int> &nums) {
        int n = nums.size(), sum = nums[0], ans = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int> &nums, long long k) {
        int n = nums.size();
        long long sum = 0, res = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum * (r - l + 1) >= k) {
                sum -= nums[l++];
            }
            res += r - l + 1;
        }
        return res;
    }
};
// @lc code=end

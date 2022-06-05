/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, res = INT_MAX;
        while (r < n) {
            sum += nums[r++];

            while (sum >= target) {
                res = min(res, r - l);
                sum -= nums[l++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

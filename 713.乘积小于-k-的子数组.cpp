/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int winProduct = 1;
        int left = 0, right = 0;
        int res = 0;
        while (right < nums.size()) {
            // 取数，移动右侧
            winProduct *= nums[right++];

            while (winProduct >= k && left < right) {
                // 取数，移动左侧
                winProduct /= nums[left++];
            }
            res += right - left;
        }
        return res;
    }
};
// @lc code=end

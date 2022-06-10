/*
 * @lc app=leetcode.cn id=1283 lang=cpp
 *
 * [1283] 使结果不超过阈值的最小除数
 */

// @lc code=start
class Solution {
public:
    int smallestDivisor(vector<int> &nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            int sum = 0;
            for (int num : nums) {
                // 向上取整
                sum += (num + mid - 1) / mid;
            }
            if (sum > threshold) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
// @lc code=end

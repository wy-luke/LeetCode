/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (mid != n - 1 && nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

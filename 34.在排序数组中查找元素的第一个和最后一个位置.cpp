/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l == nums.size() || nums[l] != target) {
            return {-1, -1};
        } else {
            int tmp = l;
            r = nums.size();
            while (l < r) {
                int mid = l + ((r - l) >> 1);
                if (nums[mid] <= target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return {tmp, l - 1};
        }
    }
};
// @lc code=end

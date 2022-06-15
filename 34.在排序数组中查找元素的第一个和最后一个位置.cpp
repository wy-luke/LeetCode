/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        int l = 0, r = n;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int firstEqual;
        if (l < n && nums[l] == target) firstEqual = l;
        else return {-1, -1};

        r = n;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return {firstEqual, l - 1};
    }
};
// @lc code=end

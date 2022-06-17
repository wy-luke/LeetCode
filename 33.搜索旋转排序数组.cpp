/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            // 当目标在左边部分
            if (target >= nums[0]) {
                // 当 mid 在左边部分，且值小于 target 时，向右收缩
                // 当 mid 在右边部分，或在左边部分且值 大于等于 target 时，向左收缩
                // 最后结果是第一个大于等于 target 的下标
                if (nums[mid] >= nums[0] && nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else { // 当目标在右边部分
                // 当 mid 在左边部分，或值小于 target 时，向右收缩
                // 当 mid 在右边部分，且值 大于等于 target 时，向左收缩
                // 最后结果是第一个大于等于 target 的下标
                if (nums[mid] >= nums[0] || nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
        if (l == nums.size() || nums[l] != target) {
            return -1;
        } else {
            return l;
        }
    }
};
// @lc code=end

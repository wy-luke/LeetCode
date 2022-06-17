/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n;
        // 先查找分界点
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        // 把区间变为目标所在区间
        if (target >= nums[0]) {
            l = 0;
        } else {
            r = n;
        }
        // 在目标区间搜索
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
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

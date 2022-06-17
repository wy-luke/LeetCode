/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        // 保证数组二段性，即左部分 >=nums[0]，右部分 <nums[0]
        while (r >= 0 && nums[r] == nums[0]) --r;
        // 此时 nums[r]<nums[0]，如果 r<0，说明数组中全部数字相同
        int tmp = r;
        // 现在 [0,r] 内查找分界点
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // 此时 r<l，l为右部分第一个，r为左部分最后一个
        // 把区间变为目标所在区间
        if (target >= nums[0]) {
            l = 0;
        } else {
            r = tmp;
        }
        // 在 [l,r] 区间搜索
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (l == nums.size() || nums[l] != target) {
            return false;
        } else {
            return true;
        }
    }
};
// @lc code=end

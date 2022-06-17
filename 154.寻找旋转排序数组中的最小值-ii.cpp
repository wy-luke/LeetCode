/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        // 保证数组二段性，即左部分 >=nums[0]，右部分 <nums[0]
        while (r >= 0 && nums[r] == nums[0]) --r;
        // 此时 nums[r]!=nums[0]，如果 nums[r]>=nums[0]说明只有左部分，否则说明有右部分
        // 现在 [0,r] 内查找分界点
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // 理论上 l 为右部分第一个
        // l != n 时：
        // 当存在右部分，l 就是右部分第一个，即为最小值
        // 当不存在右部分，说明原数组右部分都是和 nums[0] 相同的，nums[l] 就是 nums[0]，即为最小值
        // l==n 时，说明不存在右部分，nums[0] 即为最小值
        return l == n ? nums[0] : nums[l];
    }
};
// @lc code=end

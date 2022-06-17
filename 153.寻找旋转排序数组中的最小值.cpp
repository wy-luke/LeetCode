/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        // 查找分界点
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // 理论上 l 为右部分第一个
        // l != n 时，说明存在右部分，l 就是右部分第一个，即为最小值
        // l == n 时，说明不存在右部分，nums[0] 即为最小值
        return l == n ? nums[0] : nums[l];
    }
};
// @lc code=end

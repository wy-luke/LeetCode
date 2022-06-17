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
        int tmp = r;
        // [0,tmp] 可以理解为我们我们的新查找区间，下标 tmp+1 相当于 .end()
        // 现在 [0,tmp] 内查找分界点
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // 此时 r<l，l为右部分第一个，r为左部分最后一个
        // l==tmp+1 相当于找到了 nums.end()，也就是没有右部分，所以 nums[0] 就是最小
        // 否则，l 就是右部分第一个，就是最小的元素
        if (l == tmp + 1) {
            return nums[0];
        } else {
            return nums[l];
        }
    }
};
// @lc code=end

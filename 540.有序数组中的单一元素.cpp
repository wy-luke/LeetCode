/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            mid -= mid & 1;
            // 防止过界，且 mid==nums.size()-1 时归为 else
            if (mid != nums.size() - 1 && nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                r = mid - 2;
            }
        }
        return nums[l];
    }
};
// @lc code=end

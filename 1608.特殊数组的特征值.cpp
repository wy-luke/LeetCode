/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start
class Solution {
public:
    int specialArray(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (getCnt(nums, mid) > mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return getCnt(nums, l) == l ? l : -1;
    }
    // 找到数组内大于等于 num 的数量
    int getCnt(vector<int> &nums, int num) {
        // int idx = lower_bound(nums.begin(), nums.end(), num) - nums.begin();
        // return nums.size() - idx;
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < num) {
                // 不断循环，mid 能够取到最后一个满足 nums[mid] < num 的值
                // 因此 l=mid+1 就是第一个满足 nums[mid] >= num 的值
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums.size() - l;
    }
};
// @lc code=end

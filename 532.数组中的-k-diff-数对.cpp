/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            j = lower_bound(nums.begin() + j, nums.end(), nums[i] + k) - nums.begin();
            // 对于 k=0 时，要排除搜到其本身的情况，再 ++j，k!=0 时，不会搜到其本身
            if (j == i) ++j;
            if (j < n && nums[j] == nums[i] + k && j != i) ++res;
        }
        return res;
    }
};
// @lc code=end

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
        int j = 1, res = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            // 对于 k=0 时，要排除搜到其本身的情况，再 ++j
            while (j < n && nums[j] < nums[i] + k || j == i) ++j;
            if (j < n && nums[j] == nums[i] + k) ++res;
        }
        return res;
    }
};
// @lc code=end

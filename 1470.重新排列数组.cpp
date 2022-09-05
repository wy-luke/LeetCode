/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int> &nums, int n) {
        vector<int> ans;
        ans.reserve(2 * n);
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(nums[i]);
            ans.emplace_back(nums[n + i]);
        }
        return ans;
    }
};
// @lc code=end

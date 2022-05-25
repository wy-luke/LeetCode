/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    }
};
// @lc code=end

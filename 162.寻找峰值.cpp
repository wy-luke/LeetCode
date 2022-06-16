/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        // 由高中数学可知，峰值即为 极大值，而最大值一定为 极大值
        return max_element(nums.begin(), nums.end()) - nums.begin();
    }
};
// @lc code=end

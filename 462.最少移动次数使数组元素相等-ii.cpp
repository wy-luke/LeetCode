/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        int res = 0;
        for (int num : nums) {
            res += abs(num - mid);
        }
        return res;
    }
};
// @lc code=end

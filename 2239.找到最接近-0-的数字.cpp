/*
 * @lc app=leetcode.cn id=2239 lang=cpp
 *
 * [2239] 找到最接近 0 的数字
 */

// @lc code=start
class Solution {
public:
    int findClosestNumber(vector<int> &nums) {
        int res = INT_MAX;
        for (int num : nums) {
            if (abs(num) < abs(res) || (abs(num) == abs(res) && num > res)) {
                res = num;
            }
        }
        return res;
    }
};
// @lc code=end

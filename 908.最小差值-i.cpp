/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int> &nums, int k) {
        int maxNum = INT_MIN, minNum = INT_MAX;
        for (int num : nums) {
            maxNum = max(num, maxNum);
            minNum = min(num, minNum);
        }
        if (abs(maxNum - minNum) <= 2 * k) {
            return 0;
        } else {
            return maxNum - minNum - 2 * k;
        }
    }
};
// @lc code=end

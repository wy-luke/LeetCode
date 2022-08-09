/*
 * @lc app=leetcode.cn id=1413 lang=cpp
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
class Solution {
public:
    int minStartValue(vector<int> &nums) {
        int sum = 0, minVal = 0;
        for (int num : nums) {
            sum += num;
            minVal = min(sum, minVal);
        }
        return -minVal + 1;
    }
};
// @lc code=end

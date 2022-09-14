/*
 * @lc app=leetcode.cn id=1619 lang=cpp
 *
 * [1619] 删除某些元素后的数组均值
 */

// @lc code=start
class Solution {
public:
    double trimMean(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int sum = accumulate(arr.begin() + n / 20, arr.begin() + (19 * n / 20), 0);
        return sum / (n * 0.9);
    }
};
// @lc code=end

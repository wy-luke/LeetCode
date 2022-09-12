/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start
class Solution {
public:
    int specialArray(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= n; ++i) {
            int idx = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            if (n - idx == i) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

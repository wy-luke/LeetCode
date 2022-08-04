/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> minSubsequence(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater());
        int select = 0;
        vector<int> res;
        for (int num : nums) {
            select += num;
            res.emplace_back(num);
            sum -= num;
            if (select > sum) break;
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        // 也可以不用 lambda 直接 sort
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        vector<vector<int>> res;
        res.emplace_back(intervals[0]);
        int j = 1;
        while (j < intervals.size()) {
            if (res.back()[1] >= intervals[j][0]) {
                res.back()[1] = max(res.back()[1], intervals[j][1]);
            } else {
                res.emplace_back(intervals[j]);
            }
            ++j;
        }
        return res;
    }
};
// @lc code=end

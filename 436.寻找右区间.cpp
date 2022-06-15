/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        int n = intervals.size();
        vector<pair<int, int>> itvIdx;
        itvIdx.reserve(n);
        for (int i = 0; i < n; ++i) {
            itvIdx.emplace_back(intervals[i][0], i);
        }
        sort(itvIdx.begin(), itvIdx.end());
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            int idx = lower_bound(itvIdx.begin(), itvIdx.end(), make_pair(intervals[i][1], 0)) - itvIdx.begin();
            if (idx != n) res[i] = itvIdx[idx].second;
        }
        return res;
    }
};
// @lc code=end

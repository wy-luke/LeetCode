/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        // 题目说明每个区间 start 均不相同
        // 记录每个 start 出现的 index
        map<int, int> mp;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            mp[intervals[i][0]] = i;
        }
        vector<int> res;
        res.reserve(n);
        for (auto &interval : intervals) {
            // 找到第一个 start >= (该区间 end) 的区间
            auto p = mp.lower_bound(interval[1]);
            if (p == mp.end()) {
                res.emplace_back(-1);
            } else {
                res.emplace_back(p->second);
            }
        }
        return res;
    }
};
// @lc code=end

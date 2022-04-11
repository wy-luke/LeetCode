/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        backtrack(n, k, track, 1);
        return res;
    }
    void backtrack(int n, int k, vector<int> &track, int start) {
        if (track.size() == k) {
            res.emplace_back(track);
            return;
        }

        for (int i = start; i <= n; ++i) {
            track.emplace_back(i);
            backtrack(n, k, track, i + 1);
            track.pop_back();
        }
    }
};
// @lc code=end

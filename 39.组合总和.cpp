/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;
    int trackSum = 0;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtrack(candidates, target, 0);
        return res;
    }

    void backtrack(vector<int> &candidates, int target, int start) {
        if (trackSum == target) {
            res.emplace_back(track);
            return;
        } else if (trackSum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            track.emplace_back(candidates[i]);
            trackSum += candidates[i];
            backtrack(candidates, target, i);
            track.pop_back();
            trackSum -= candidates[i];
        }
    }
};
// @lc code=end

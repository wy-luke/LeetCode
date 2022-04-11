// @before-stub-for-debug-begin
#include "commoncppproblem40.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;
    int trackSum = 0;

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            track.emplace_back(candidates[i]);
            trackSum += candidates[i];
            backtrack(candidates, target, i + 1);
            track.pop_back();
            trackSum -= candidates[i];
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> track;
        backtrack(nums, track, 0);
        return res;
    }

    void backtrack(vector<int> &nums, vector<int> &track, int start) {
        res.emplace_back(track);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            track.emplace_back(nums[i]);
            backtrack(nums, track, i + 1);
            track.pop_back();
        }
    }
};
// @lc code=end

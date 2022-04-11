/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> track;
        backtrack(nums, track, 0);
        return res;
    }

    void backtrack(vector<int> &nums, vector<int> &track, int start) {
        res.emplace_back(track);
        for (int i = start; i < nums.size(); ++i) {
            track.emplace_back(nums[i]);
            backtrack(nums, track, i + 1);
            track.pop_back();
        }
    }
};
// @lc code=end

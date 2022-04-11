/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;
    vector<bool> visited;

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        visited.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int> &nums) {
        if (track.size() == nums.size()) {
            res.emplace_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;

            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            track.emplace_back(nums[i]);
            visited[i] = true;
            backtrack(nums);
            track.pop_back();
            visited[i] = false;
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        vector<int> track;
        vector<bool> visited(n, false);
        backtrack(nums, track, visited);
        return res;
    }

    void backtrack(vector<int> &nums, vector<int> &track, vector<bool> &visited) {
        if (track.size() == nums.size()) {
            res.emplace_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            track.emplace_back(nums[i]);
            visited[i] = true;
            backtrack(nums, track, visited);
            track.pop_back();
            visited[i] = false;
        }
    }
};
// @lc code=end

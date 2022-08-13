/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < groupSizes.size(); ++i) {
            mp[groupSizes[i]].emplace_back(i);
        }
        vector<vector<int>> ans;
        for (auto const &[key, val] : mp) {
            for (int i = 0; i < val.size(); i += key) {
                vector<int> group;
                group.reserve(key);
                for (int j = 0; j < key; ++j) {
                    group.emplace_back(val[i + j]);
                }
                ans.emplace_back(group);
            }
        }
        return ans;
    }
};
// @lc code=end

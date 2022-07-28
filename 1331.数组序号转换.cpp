/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); ++i) {
            mp[arr[i]].emplace_back(i);
        }
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        int idx = 1;
        for (int i = 0; i < arr.size();) {
            for (int j : mp[tmp[i]]) {
                arr[j] = idx;
            }
            i += mp[tmp[i]].size();
            ++idx;
        }
        return arr;
    }
};
// @lc code=end

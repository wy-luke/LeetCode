/*
 * @lc app=leetcode.cn id=2301 lang=cpp
 *
 * [2301] 替换字符后匹配
 */

// @lc code=start
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>> &mappings) {
        unordered_map<char, unordered_set<char>> mp;
        for (int i = 0; i < mappings.size(); ++i) {
            mp[mappings[i][0]].emplace(mappings[i][1]);
        }
        int n = s.size(), m = sub.size();
        for (int i = 0; i < n - m + 1; ++i) {
            int j = 0;
            for (; j < m; ++j) {
                if (s[i + j] != sub[j] && mp[sub[j]].count(s[i + j]) == 0) break;
            }
            if (j == m) return true;
        }
        return false;
    }
};
// @lc code=end

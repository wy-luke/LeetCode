/*
 * @lc app=leetcode.cn id=6051 lang=cpp
 *
 * [6051] 统计是给定字符串前缀的字符串数目
 */

// @lc code=start
class Solution {
public:
    int countPrefixes(vector<string> &words, string s) {
        unordered_set<string> mp;
        for (int i = 1; i <= s.size(); ++i) {
            mp.emplace(s.substr(0, i));
        }
        int res = 0;
        for (string s : words) {
            if (mp.count(s) != 0) ++res;
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */

// @lc code=start
class Solution {
public:
    vector<int> check(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            if (mp.count(s[i]) != 0) {
                res.push_back(mp[s[i]]);
            } else {
                res.push_back(i);
                mp[s[i]] = i;
            }
        }
        return res;
    }
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<int> ptn = check(pattern);
        vector<string> res;
        for (string word : words) {
            if (check(word) == ptn) res.emplace_back(word);
        }
        return res;
    }
};
// @lc code=end

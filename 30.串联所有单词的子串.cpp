/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> res;
        int n = s.size(), m = words.size(), wsize = words[0].size();
        for (int i = 0; i < wsize && i < n - m * wsize + 1; ++i) {
            unordered_map<string, int> win;
            for (int j = 0; j < m; ++j) {
                win[s.substr(i + j * wsize, wsize)]++;
            }
            for (string &word : words) {
                if (--win[word] == 0) win.erase(word);
            }
            for (int j = i; j < n - m * wsize + 1; j += wsize) {
                if (win.empty()) res.emplace_back(j);

                if (--win[s.substr(j, wsize)] == 0) win.erase(s.substr(j, wsize));
                if (++win[s.substr(j + m * wsize, wsize)] == 0) win.erase(s.substr(j + m * wsize, wsize));
            }
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1408 lang=cpp
 *
 * [1408] 数组中的字符串匹配
 */

// @lc code=start
class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> res;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    res.emplace_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

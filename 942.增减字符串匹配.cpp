/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int lo = 0, hi = n;
        vector<int> res(n + 1);
        for (int i = 0; i < n; ++i) {
            res[i] = s[i] == 'I' ? lo++ : hi--;
        }
        res[n] = lo;
        return res;
    }
};
// @lc code=end

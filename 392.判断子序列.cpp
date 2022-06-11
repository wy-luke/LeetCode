/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == s[idx]) ++idx;
            if (idx == s.size()) return true;
        }
        // 注意 s t 均为空的情况，不能直接返回 false
        return idx == s.size();
    }
};
// @lc code=end

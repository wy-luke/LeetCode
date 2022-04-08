/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            string s1 = isPal(s, i, i);
            string s2 = isPal(s, i, i + 1);
            res = s1.size() > res.size() ? s1 : res;
            res = s2.size() > res.size() ? s2 : res;
        }
        return res;
    }

    // 寻找以 l r 为中心的回文子串
    string isPal(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        return s.substr(l + 1, r - l - 1);
    }
};
// @lc code=end

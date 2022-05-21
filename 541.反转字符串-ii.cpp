/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    void reverseK(string &s, int start, int k) {
        int end = start + k - 1;
        while (start < end) {
            char tmp = s[start];
            s[start++] = s[end];
            s[end--] = tmp;
        }
    }

    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            reverseK(s, i, min(k, n - i));
        }
        return s;
    }
};
// @lc code=end

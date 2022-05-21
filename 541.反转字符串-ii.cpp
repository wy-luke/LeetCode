/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            // i + min(k, n - i) 可以合并为 min(i+k, n)
            reverse(s.begin() + i, s.begin() + i + min(k, n - i));
        }
        return s;
    }
};
// @lc code=end

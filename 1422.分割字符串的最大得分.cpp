/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int cnt0 = 0, cnt1 = 0;
        for (char c : s) {
            if (s[i] == '1') {
                cnt1++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0') {
                cnt0++;
            } else {
                cnt1--;
            }
            ans = max(ans, cnt0 + cnt1);
        }
        return ans;
    }
};
// @lc code=end

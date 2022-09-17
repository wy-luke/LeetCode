/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<int, int> mp;
        int n = s.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (mp.count(c)) {
                ans = max(ans, i - mp[c] - 1);
            } else {
                mp[c] = i;
            }
        }
        return ans;
    }
};
// @lc code=end

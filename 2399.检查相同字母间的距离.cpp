/*
 * @lc app=leetcode.cn id=2399 lang=cpp
 *
 * [2399] 检查相同字母间的距离
 */

// @lc code=start
class Solution {
public:
    bool checkDistances(string s, vector<int> &distance) {
        unordered_map<int, int> mp;
        for (int i = 0; i < s.size(); ++i) {
            int x = s[i] - 'a';
            if (mp.count(x) && distance[x] != i - mp[x] - 1) {
                return false;
            } else {
                mp[x] = i;
            }
        }
        return true;
    }
};
// @lc code=end

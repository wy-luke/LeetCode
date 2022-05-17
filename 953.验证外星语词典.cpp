/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); ++i) {
            mp[order[i]] = i;
        }
        // 遍历找出所有 false
        for (int i = 1; i < words.size(); ++i) {
            int m = words[i - 1].size(), n = words[i].size();
            int j = 0;
            for (; j < min(m, n); ++j) {
                if (mp[words[i][j]] < mp[words[i - 1][j]]) {
                    return false; // 如果反序，直接返回 false
                } else if (mp[words[i][j]] > mp[words[i - 1][j]]) {
                    break; // 如果正序，直接比较下一个
                }
                // 如果相等，则比较下一个字符
            }
            // 如果字符比较完成（即都相同） 且前面的字符长，则返回 false
            if (j == n && j < m) return false;
            // 如果后面的字符长，符合顺序，不管，开始往后比较
        }
        return true;
    }
};
// @lc code=end

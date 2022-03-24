/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // 哈希表记录每个字符出现的次数
        unordered_map<char, int> need, window;
        for (char i : t) need[i]++;

        int left = 0, right = 0;         // 窗口，左闭右开
        int valid = 0;                   // 当前窗口包含的有效字符数
        int start = 0, length = INT_MAX; // 最优解的起始索引和长度
        
        while (right < s.size()) {
            // 获取字符，移动窗口右侧
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                // 若某个字符出现的次数和目标次数相等，则有效字符数加一
                if (window[c] == need[c]) valid++;
            }

            // 当有效字符数和所需要的字符数相等时，进行左侧滑窗
            while (valid == need.size()) {
                // 更新 start, length
                if (right - left < length) {
                    start = left;
                    length = right - left;
                }

                // 获取字符，移动窗口左侧
                char c2 = s[left];
                left++;
                if (need.count(c2)) {
                    if (window[c2] == need[c2]) valid--;
                    window[c2]--;
                }
            }
        }
        return length == INT_MAX ? "" : s.substr(start, length);
    }
};
// @lc code=end

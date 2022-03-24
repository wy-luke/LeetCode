/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 哈希表记录每个字符出现的次数
        unordered_map<char, int> need, window;
        for (char i : s1) need[i]++;

        int left = 0, right = 0; // 窗口，左闭右开
        int valid = 0;           // 当前窗口包含的有效字符数

        while (right < s2.size()) {
            // 获取字符，移动窗口右侧
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                // 若某个字符出现的次数和目标次数相等，则有效字符数加一
                if (window[c] == need[c]) valid++;
            }

            // 当窗口大小等于目标长度时，进行左侧滑窗
            while (right - left >= s1.size()) {
                // 判断是否满足条件
                if (valid == need.size()) return true;

                // 获取字符，移动窗口左侧
                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> have;

        int left = 0, right = 0;
        int length = 0;

        while (right < s.size()) {
            char c = s[right];
            right++;

            have[c]++;
            // 当包含重复字符时，移动左侧窗口
            while (have[c] != 1) {
                char d = s[left];
                left++;
                have[d]--;
            }
            length = max(length, right - left);
        }
        return length;
    }
};
// @lc code=end

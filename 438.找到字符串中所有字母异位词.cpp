/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> need, window; // 哈希表记录字符个数
        for (char i : p)
            need[i]++;

        int left = 0, right = 0;
        int valid = 0;

        while (right < s.size()) {
            char c = s[right];
            right++;

            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (right - left == p.size()) {
                if (valid == need.size()) res.emplace_back(left);

                char c2 = s[left];
                left++;
                if (need.count(c2)) {
                    if (window[c2] == need[c2]) valid--;
                    window[c2]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

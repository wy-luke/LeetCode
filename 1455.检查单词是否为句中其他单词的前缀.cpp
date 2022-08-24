/*
 * @lc app=leetcode.cn id=1455 lang=cpp
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int p = 0, q = 0, m = sentence.size(), n = searchWord.size();
        int idx = 1;
        while (p < m) {
            while (p < m && q < n && sentence[p] == searchWord[q]) {
                ++p;
                ++q;
            }
            if (q == n) {
                return idx;
            } else {
                while (p < m && sentence[p++] != ' ') {
                }
            }
            ++idx;
            q = 0;
        }
        return -1;
    }
};
// @lc code=end

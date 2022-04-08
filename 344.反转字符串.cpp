/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char> &s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left;
            --right;
        }
    }
};
// @lc code=end

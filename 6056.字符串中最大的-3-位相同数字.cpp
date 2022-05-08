/*
 * @lc app=leetcode.cn id=6056 lang=cpp
 *
 * [6056] 字符串中最大的 3 位相同数字
 */

// @lc code=start
class Solution {
public:
    string largestGoodInteger(string num) {
        for (char i = '9'; i >= '0'; --i) {
            string s(3, i);
            if (num.find(s) != string::npos) return s;
        }
        return "";
    }
};
// @lc code=end

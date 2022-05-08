/*
 * @lc app=leetcode.cn id=6056 lang=cpp
 *
 * [6056] 字符串中最大的 3 位相同数字
 */

// @lc code=start
class Solution {
public:
    string largestGoodInteger(string num) {
        int maxV = -1;
        string res = "";
        for (int i = 0; i < num.size() - 2; ++i) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                if (num[i] - '0' > maxV) {
                    res = num.substr(i, 3);
                    maxV = num[i] - '0';
                }
            }
        }
        return res;
    }
};
// @lc code=end

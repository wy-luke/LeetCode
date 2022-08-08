/*
 * @lc app=leetcode.cn id=761 lang=cpp
 *
 * [761] 特殊的二进制序列
 */

// @lc code=start
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) {
            return s;
        }
        vector<string> subs;
        // i遍历，j记录当前sub开始位置，k记录当前sub的累加和(0当作-1)
        for (int i = 0, j = 0, k = 0; i < s.size(); ++i) {
            k += s[i] == '1' ? 1 : -1;
            if (k == 0) {
                subs.emplace_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(subs.begin(), subs.end(), greater<string>());
        // accumulate 要定义初始值，然后累加
        // 然而单纯的 "" 是一个字符串字面值，即常量，无法对其进行累加
        // 所以使用 ""s 运算符，返回 字符串字面值 对应的一个 字符串变量
        // 当然这里也可以使用 string() 构造一个字符串变量，初始值默认为空 ""
        string ans = accumulate(subs.begin(), subs.end(), ""s);
        return ans;
    }
};
// @lc code=end

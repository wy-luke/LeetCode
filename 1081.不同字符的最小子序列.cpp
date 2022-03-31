/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        string res;
        // 字母是否在 res 中
        vector<bool> inRes(26);
        // s 中每个字母的个数
        vector<int> num(26);
        for (char i : s) {
            ++num[i - 'a'];
        }

        for (char i : s) {
            --num[i - 'a'];

            if (inRes[i - 'a']) continue;

            while (!res.empty() && i < res.back()) {
                if (num[res.back() - 'a'] == 0) break;
                inRes[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(i);
            inRes[i - 'a'] = true;
        }
        return res;
    }
};
// @lc code=end

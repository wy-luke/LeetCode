/*
 * @lc app=leetcode.cn id=2269 lang=cpp
 *
 * [2269] 找到一个数字的 K 美丽值
 */

// @lc code=start
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();
        int res = 0;
        for (int i = 0; i <= n - k; ++i) {
            int x = stoi(s.substr(i, k));
            if (x == 0) continue;
            if (num % x == 0) res++;
        }
        return res;
    }
};
// @lc code=end

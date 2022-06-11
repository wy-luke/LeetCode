/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // 前缀和
        int n = s.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (s[i] - '0');
        }
        int res = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            // 计算当 i 左侧（不含）为 0，i 右侧（包含）为 1 时的翻转次数
            // pre[i] 为 i 左侧的和，即有多少个 1，即翻转为 0 需要的次数
            // n-i 为 i 右侧共有的数字个数，pre[n]-pre[i] 为 i 右侧 1 的个数，差即为 0 的个数，即翻转为 1 需要的次数
            // 两者和为总共需要翻转的次数
            res = min(res, pre[i] + (n - i) - (pre[n] - pre[i]));
        }
        return res;
    }
};
// @lc code=end

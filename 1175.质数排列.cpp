/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 */

// @lc code=start
class Solution {
    const int MOD = 1e9 + 7;

public:
    // 检查是否为质数
    bool check(int x) {
        for (int i = 2; i < x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        // cnt 为质数的个数
        int res = 1, cnt = 1;
        for (int i = 2; i <= n; ++i) {
            if (check(i)) {
                res = ((long long)res * cnt) % MOD;
                ++cnt;
            } else {
                res = ((long long)res * (i - cnt + 1)) % MOD;
            }
        }
        return res;
    }
};
// @lc code=end

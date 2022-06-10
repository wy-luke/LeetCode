/*
 * @lc app=leetcode.cn id=730 lang=cpp
 *
 * [730] 统计不同回文子序列
 */

// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPalindromicSubsequences(string s) {
        // 动态规划，具体见题解
        int n = s.size();
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(n)));
        for (int i = 0; i < n; ++i) {
            dp[s[i] - 'a'][i][i] = 1;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = len - 1; j < n; ++i, ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (s[i] - 'a' == k && s[j] - 'a' == k) {
                        int sum = 0;
                        for (int m = 0; m < 4; ++m) {
                            sum = (sum + dp[m][i + 1][j - 1]) % MOD;
                        }
                        dp[k][i][j] = 2 + sum;
                    } else if (s[i] - 'a' != k && s[j] - 'a' != k) {
                        dp[k][i][j] = dp[k][i + 1][j - 1];
                    } else if (s[i] - 'a' != k) {
                        dp[k][i][j] = dp[k][i + 1][j];
                    } else {
                        dp[k][i][j] = dp[k][i][j - 1];
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < 4; ++i) {
            res = (res + dp[i][0][n - 1]) % MOD;
        }
        return res;
    }
};
// @lc code=end

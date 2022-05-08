/*
 * @lc app=leetcode.cn id=6058 lang=cpp
 *
 * [6058] 统计打字方案数
 */

// @lc code=start
class Solution {
public:
    int countTexts(string pressedKeys) {
        // 1e9 表示 10^9
        const long long MOD = 1e9 + 7;
        int n = pressedKeys.size();
        // 构造每个长度对应的可能数，是一个斐波那契数列
        vector<long long> dp3{1, 1, 2, 4}, dp4{1, 1, 2, 4};
        dp3.resize(n + 1);
        dp4.resize(n + 1);
        for (int i = 4; i <= n; ++i) {
            dp3[i] = (dp3[i - 1] + dp3[i - 2] + dp3[i - 3]) % MOD;
            dp4[i] = (dp4[i - 1] + dp4[i - 2] + dp4[i - 3] + dp4[i - 4]) % MOD;
        }

        int count = 0;
        long long res = 1;
        for (int i = 0; i < n; ++i) {
            // 这里把 ++count 放在上面，小技巧
            ++count;
            // 防止数组过界，先判断 i == n - 1
            if (i == n - 1 || pressedKeys[i + 1] != pressedKeys[i]) {
                if (pressedKeys[i] == '7' || pressedKeys[i] == '9') {
                    res = res * dp4[count] % MOD;
                } else {
                    res = res * dp3[count] % MOD;
                }
                count = 0;
            }
        }
        return res;
    }
};
// @lc code=end
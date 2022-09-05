/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
class Solution {
public:
    int maximumRows(vector<vector<int>> &mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        // 把每行当作一个2进制数，转成10进制存进masks
        vector<int> masks(m);
        for (int i = 0; i < m; ++i) {
            int k = 0;
            for (int j = 0; j < n; ++j) {
                // 每行的每个数字左移 n - j - 1 位再相加
                // 如101: 100+00+1=101
                k += mat[i][j] << (n - j - 1);
            }
            masks[i] = k;
        }
        // 用一个 n 位的二进制数表示选择，1表示选择该列，0表示不选择
        // 则一共 000 -> 111 共 2^n -1 个选择
        // 则可以枚举 0 到 2^n -1，表示所有选择
        int len = 1 << n, ans = 0;
        for (int i = 0; i < len; ++i) {
            // 统计当前数的二进制有几个 1
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                cnt += (i >> j) & 1;
            }
            if (cnt != cols) {
                continue;
            }
            // 统计覆盖行数
            cnt = 0;
            for (int mask : masks) {
                // 注意位运算的优先级很低！！！加括号！！！
                if ((i & mask) == mask) {
                    ++cnt;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1292 lang=cpp
 *
 * [1292] 元素和小于等于阈值的正方形的最大边长
 */

// @lc code=start
class Solution {
public:
    bool check(vector<vector<int>> &pre, int threshold, int target) {
        int m = pre.size() - 1, n = pre[0].size() - 1;
        for (int i = 0; i < m - target + 1; ++i) {
            for (int j = 0; j < n - target + 1; ++j) {
                if (pre[i + target][j + target] - pre[i][j + target] - pre[i + target][j] + pre[i][j] <= threshold) return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>> &mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        // 二维前缀和
        vector<vector<int>> pre(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + mat[i][j];
            }
        }
        // mid 取值范围为 1 到 min(m,n)，取 0 时无意义，不可
        int l = 1, r = min(m, n);
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(pre, threshold, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // l 为第一个不满足 check 的，最差为 1 也不满足，则返回 0，符合题意
        return l - 1;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        res.reserve(m * n);
        // 一共 m+n-1 条对角线
        for (int i = 0; i < m + n - 1; ++i) {
            if (i % 2 == 0) {
                int row = i >= m ? m - 1 : i;
                int col = i >= m ? i - m + 1 : 0;
                while (row >= 0 && col < n) {
                    res.emplace_back(mat[row--][col++]);
                }
            } else {
                int row = i >= n ? i - n + 1 : 0;
                int col = i >= n ? n - 1 : i;
                while (row < m && col >= 0) {
                    res.emplace_back(mat[row++][col--]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

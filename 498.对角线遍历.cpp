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
        bool flag = true;
        // 表示每个对角线的起点，1 和 2 表示不同方向
        int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
        // 表示每个加入 res 的 idx
        int row, col;
        vector<int> res;
        res.reserve(m * n);
        for (int i = 0; i < m + n - 1; ++i) {
            if (flag) {
                row = row1;
                col = col1;
                while (row >= 0 && col < n) {
                    res.emplace_back(mat[row--][col++]);
                }
            } else {
                row = row2;
                col = col2;
                while (row < m && col >= 0) {
                    res.emplace_back(mat[row++][col--]);
                }
            }
            flag = !flag;
            // 更新对角线起点 idx
            if (row1 + 1 < m) {
                ++row1;
            } else {
                ++col1;
            }
            if (col2 + 1 < n) {
                ++col2;
            } else {
                ++row2;
            }
        }
        return res;
    }
};
// @lc code=end

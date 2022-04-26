/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */

// @lc code=start
class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int n = grid.size();
        int res = 0, rowMax, colMax;
        for (int i = 0; i < n; ++i) {
            rowMax = 0;
            colMax = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) ++res;
                rowMax = max(rowMax, grid[i][j]);
                colMax = max(colMax, grid[j][i]);
            }
            res += rowMax + colMax;
        }
        return res;
    }
};
// @lc code=end

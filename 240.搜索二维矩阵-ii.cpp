/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    int bs(vector<vector<int>> &matrix, bool isVertical, int idx, int target) {
        int l, r;
        if (isVertical) {
            l = 0, r = matrix.size();
        } else {
            l = 0, r = matrix[0].size();
        }
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            int midValue;
            if (isVertical) {
                midValue = matrix[mid][idx];
            } else {
                midValue = matrix[idx][mid];
            }
            if (midValue < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row1 = bs(matrix, true, 0, target);
        if (row1 < m && matrix[row1][0] == target) return true;
        int row2 = bs(matrix, true, n - 1, target);
        if (row2 < m && matrix[row2][n - 1] == target) return true;
        for (int i = row2; i < row1; ++i) {
            int idx = bs(matrix, false, i, target);
            if (matrix[i][idx] == target) return true;
        }
        return false;
    }
};
// @lc code=end

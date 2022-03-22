/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int m = matrix.size();
        // 首先按对角线镜像
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 然后按行反转
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                swap(matrix[i][j], matrix[i][m - j - 1]);
            }
        }
    }
};
// @lc code=end

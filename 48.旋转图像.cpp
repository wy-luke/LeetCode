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
        int n = matrix[0].size();
        // 首先按对角线镜像
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        // 然后按行反转
        for (int k = 0; k < m; ++k) {
            int a = 0, b = n - 1;
            while (a < b) {
                int tmp = matrix[k][a];
                matrix[k][a] = matrix[k][b];
                matrix[k][b] = tmp;
                a++;
                b--;
            }
        }
    }
};
// @lc code=end

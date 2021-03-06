/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, top = 0;
        int right = n - 1, bottom = m - 1;
        vector<int> res;
        res.reserve(m * n);
        while (true) {
            for (int i = left; i <= right; ++i) {
                res.emplace_back(matrix[top][i]);
            }
            if (++top > bottom) break;

            for (int i = top; i <= bottom; ++i) {
                res.emplace_back(matrix[i][right]);
            }
            if (--right < left) break;

            for (int i = right; i >= left; --i) {
                res.emplace_back(matrix[bottom][i]);
            }
            if (--bottom < top) break;

            for (int i = bottom; i >= top; --i) {
                res.emplace_back(matrix[i][left]);
            }
            if (++left > right) break;
        }
        return res;
    }
};
// @lc code=end

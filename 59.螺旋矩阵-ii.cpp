/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;

        int num = 1;
        while (true) {
            for (int i = left; i <= right; ++i) res[top][i] = num++;
            if (++top > bottom) break;

            for (int i = top; i <= bottom; ++i) res[i][right] = num++;
            if (--right < left) break;

            for (int i = right; i >= left; --i) res[bottom][i] = num++;
            if (--bottom < top) break;

            for (int i = bottom; i >= top; --i) res[i][left] = num++;
            if (++left > right) break;
        }
        return res;
    }
};
// @lc code=end

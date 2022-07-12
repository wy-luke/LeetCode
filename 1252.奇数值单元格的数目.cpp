/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>> &indices) {
        vector<int> row(m), col(n);
        for (auto &indice : indices) {
            row[indice[0]]++;
            col[indice[1]]++;
        }
        // 记录加了偶数次的 行 和 列 的个数
        int rowCnt0 = 0, colCnt0 = 0;
        for (int i : row) {
            if (i % 2 == 0) rowCnt0++;
        }
        for (int i : col) {
            if (i % 2 == 0) colCnt0++;
        }
        // 偶 + 奇 = 奇
        // 所以结果为（偶数行的个数）*（奇数列的个数）+（奇数行的个数）*（偶数列的个数）
        return rowCnt0 * (n - colCnt0) + (m - rowCnt0) * colCnt0;
    }
};
// @lc code=end

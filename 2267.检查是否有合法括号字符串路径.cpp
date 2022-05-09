/*
 * @lc app=leetcode.cn id=2267 lang=cpp
 *
 * [2267] 检查是否有合法括号字符串路径
 */

// @lc code=start
class Solution {
public:
    int m, n;
    bool vis[105][105][205];
    bool hasValidPath(vector<vector<char>> &grid) {
        m = grid.size();
        n = grid[0].size();
        // 剪枝，不可能满足题意的状态
        if ((m + n) % 2 == 0 || grid[0][0] != '(' || grid[m - 1][n - 1] != ')') return false;
        // 开始 dfs
        return dfs(grid, 0, 0, 0);
    }
    // status 遇到 '(' 则 +1，遇到 ')' 则 -1
    bool dfs(vector<vector<char>> &grid, int status, int row, int col) {
        // 共 (m+n-1) 个，现在是第 (row+1+col+1-1) 个，剩余 (m+n-row-col-2) 个 + 本次递归的 1 个
        // 如果 status > (m+n-row-col-1) ，即使后面全为 ')' 也无法满足题意
        if (status > (m + n - row - col - 1)) return false;
        // 到最后一格，前面已经排除最后一格为 '(' 的情况，所以只需判断此时 status 是否为 1
        if (row == m - 1 && col == n - 1) return status == 1;
        // 如果曾到过某状态，则说明该状态是 false，因为如果是 true 的话会直接返回结果
        if (vis[row][col][status]) return false;
        // 标记状态
        vis[row][col][status] = true;
        // 对每格进行判断
        if (grid[row][col] == '(') {
            status++;
        } else {
            // 如果此时 status 为 0，则肯定不满足题意
            if (status == 0) return false;
            status--;
        }
        // 不过界的前提下进行下一次递归
        return (row < m - 1 && dfs(grid, status, row + 1, col)) || (col < n - 1 && dfs(grid, status, row, col + 1));
    }
};
// @lc code=end

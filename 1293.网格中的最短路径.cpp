/*
 * @lc app=leetcode.cn id=1293 lang=cpp
 *
 * [1293] 网格中的最短路径
 */

// @lc code=start
class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (k > m + n - 2) return m + n - 2;
        // 方向
        int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        // 记忆数组
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(m * n + 1, INT_MAX)));
        int res = INT_MAX;
        function<void(int, int, int, int)> dfs = [&](int x, int y, int cnt, int cnt1) -> void {
            if (grid[x][y] == 1) cnt1++;
            cnt++;

            if (cnt1 > k) return;
            if (cnt >= res) return;

            if (x == m - 1 && y == n - 1) {
                res = cnt;
                return;
            }

            if (vis[x][y][cnt1] <= cnt) return;
            vis[x][y][cnt1] = cnt;

            for (int i = 0; i < 4; ++i) {
                int newx = x + dir[i][0];
                int newy = y + dir[i][1];
                if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                    dfs(newx, newy, cnt, cnt1);
                }
            }
            return;
        };
        dfs(0, 0, -1, 0);
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end

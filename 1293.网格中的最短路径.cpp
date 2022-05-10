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
        // 剪枝
        if (k > m + n - 2) return m + n - 2;
        // 方向
        int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        // 三维记忆数组， [x][y][cnt1] 分别表示坐标和当前墙的数量，存储的值为当前状态下遍历过的最短路径长度
        // 当坐标和当前墙的数量相等时，继续带入 dfs， 递归的路径是一样的
        // 所以如果某状态下，当前路径长度大于等于 vis 记录的路径长度，继续递归，只会得到更大或相等的结果，所以直接返回
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        int res = INT_MAX;
        // cnt 记录步数，cnt1 记录经过的墙的数量
        function<void(int, int, int, int)> dfs = [&](int x, int y, int cnt, int cnt1) -> void {
            // 遇到墙 cnt1 + 1
            if (grid[x][y] == 1) cnt1++;
            // 路径长 + 1
            cnt++;
            // 剪枝
            if (cnt1 > k) return;
            if (cnt >= res) return;
            // 上面排除了不满足的情况
            if (x == m - 1 && y == n - 1) {
                res = cnt;
                return;
            }
            // 理解见上面
            if (vis[x][y][cnt1] <= cnt) return;
            // 更新 vis
            vis[x][y][cnt1] = cnt;
            // 四个方向递归
            for (int i = 0; i < 4; ++i) {
                int newx = x + dir[i][0];
                int newy = y + dir[i][1];
                if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                    dfs(newx, newy, cnt, cnt1);
                }
            }
            return;
        };
        // 因为题中要求路径长不记录第一个，所以从 -1 开始
        dfs(0, 0, -1, 0);
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end

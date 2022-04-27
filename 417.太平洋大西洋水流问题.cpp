/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int m = heights.size();
        int n = heights[0].size();
        // 记录每个节点到达次数，如果等于二则满足题意，加入 res
        vector<vector<int>> times(m, vector<int>(n));
        vector<vector<int>> res;
        // bfs
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));
        // 先看太平洋
        for (int i = 0; i < m; ++i) {
            visited[i][0] = true;
            q.emplace(i, 0);
        }
        for (int i = 1; i < n; ++i) {
            visited[0][i] = true;
            q.emplace(0, i);
        }
        vector<vector<int>> vec{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                ++times[row][col];

                for (int j = 0; j < 4; ++j) {
                    int r = row + vec[j][0];
                    int c = col + vec[j][1];

                    if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && heights[r][c] >= heights[row][col]) {
                        visited[r][c] = true;
                        q.emplace(r, c);
                    }
                }
            }
        }
        // 然后大西洋
        vector<vector<bool>> visited2(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            visited2[i][n - 1] = true;
            q.emplace(i, n - 1);
        }
        for (int i = 0; i < n - 1; ++i) {
            visited2[m - 1][i] = true;
            q.emplace(m - 1, i);
        }
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                ++times[row][col];

                if (times[row][col] == 2) res.push_back({row, col});

                for (int j = 0; j < 4; ++j) {
                    int r = row + vec[j][0];
                    int c = col + vec[j][1];
                    if (r >= 0 && r < m && c >= 0 && c < n && !visited2[r][c] && heights[r][c] >= heights[row][col]) {
                        visited2[r][c] = true;
                        q.emplace(r, c);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

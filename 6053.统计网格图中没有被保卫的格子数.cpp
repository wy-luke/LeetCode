/*
 * @lc app=leetcode.cn id=6053 lang=cpp
 *
 * [6053] 统计网格图中没有被保卫的格子数
 */

// @lc code=start
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        vector<vector<bool>> wall(m, vector<bool>(n));

        // -1 表示 wall，1 表示 guard
        // 大于 1 表示某方向上已路过该 guard，可以直接跳过
        vector<vector<int>> sp(m, vector<int>(n));
        for (auto &g : guards) {
            sp[g[0]][g[1]] = 1;
        }
        for (auto &w : walls) {
            sp[w[0]][w[1]] = -1;
        }
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        // 先进行向上和向下，即竖直方向
        for (auto &g : guards) {
            int x = g[0], y = g[1];
            // 竖直方向上已路过该 guard，可以直接跳过
            if (sp[x][y] > 1) continue;

            for (int i = x - 1; i >= 0; --i) {
                // 遇到墙
                if (sp[i][y] == -1) break;
                if (!visited[i][y]) {
                    // 遇到其他 guard 时，将该 guard ++，同时不增加 res
                    if (sp[i][y] == 1) {
                        sp[i][y]++;
                    } else {
                        ++res;
                        visited[i][y] = true;
                    }
                }
            }
            for (int i = x + 1; i < m; ++i) {
                if (sp[i][y] == -1) break;
                if (!visited[i][y]) {
                    if (sp[i][y] == 1) {
                        sp[i][y]++;
                    } else {
                        ++res;
                        visited[i][y] = true;
                    }
                }
            }
        }
        // 先把 guard 置为 1
        for (auto &g : guards) {
            sp[g[0]][g[1]] = 1;
        }
        // 然后水平方向
        for (auto &g : guards) {
            int x = g[0], y = g[1];
            // 水平方向上已路过该 guard，可以直接跳过
            if (sp[x][y] > 1) continue;
            for (int i = y - 1; i >= 0; --i) {
                if (sp[x][i] == -1) break;
                if (!visited[x][i]) {
                    if (sp[x][i] == 1) {
                        sp[x][i]++;
                    } else {
                        ++res;
                        visited[x][i] = true;
                    }
                }
            }
            for (int i = y + 1; i < n; ++i) {
                if (sp[x][i] == -1) break;
                if (!visited[x][i]) {
                    if (sp[x][i] == 1) {
                        sp[x][i]++;
                    } else {
                        ++res;
                        visited[x][i] = true;
                    }
                }
            }
        }
        return m * n - guards.size() - walls.size() - res;
    }
};
// @lc code=end

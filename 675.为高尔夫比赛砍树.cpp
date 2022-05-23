/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
class Solution {
public:
    int cutOffTree(vector<vector<int>> &forest) {
        int m = forest.size();
        int n = forest[0].size();
        map<int, pair<int, int>> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) mp[forest[i][j]] = make_pair(i, j);
            }
        }
        int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        function<int(int, int, int, int)> bfs = [&](int startx, int starty, int endx, int endy) -> int {
            int step = 0;
            queue<pair<int, int>> q;
            q.emplace(startx, starty);
            vector<vector<bool>> vis(m, vector<bool>(n));
            vis[startx][starty] = true;
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; ++i) {
                    auto [curx, cury] = q.front();
                    q.pop();
                    if (curx == endx && cury == endy) return step;
                    for (int j = 0; j < 4; ++j) {
                        int nxtx = curx + dir[j][0];
                        int nxty = cury + dir[j][1];
                        if (nxtx < 0 || nxtx >= m || nxty < 0 || nxty >= n || vis[nxtx][nxty] || forest[nxtx][nxty] == 0) continue;
                        q.emplace(nxtx, nxty);
                        vis[nxtx][nxty] = true;
                    }
                }
                ++step;
            }
            return -1;
        };
        int res = bfs(0, 0, mp.begin()->second.first, mp.begin()->second.second);
        if (res == -1) return -1;
        for (auto m = mp.begin(); m != prev(mp.end()); ++m) {
            int d = bfs(m->second.first, m->second.second, next(m)->second.first, next(m)->second.second);
            if (d == -1) return -1;
            res += d;
        }
        return res;
    }
};
// @lc code=end

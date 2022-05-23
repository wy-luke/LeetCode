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
        vector<pair<int, int>> tree;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) tree.emplace_back(i, j);
            }
        }
        // 排序技巧！！！
        sort(tree.begin(), tree.end(), [&](const auto &a, const auto &b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        // 方向数组
        int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        // 没有递归，可使用 auto
        function<int(int, int, int, int)> bfs = [&](int startx, int starty, int endx, int endy) -> int {
            if (startx == endx && starty == endy) return 0;
            int step = 1;
            queue<pair<int, int>> q;
            q.emplace(startx, starty);
            vector<vector<bool>> vis(m, vector<bool>(n));
            vis[startx][starty] = true;
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; ++i) {
                    // 技巧！！！
                    auto [curx, cury] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; ++j) {
                        int nx = curx + dir[j][0];
                        int ny = cury + dir[j][1];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny] || forest[nx][ny] == 0) continue;
                        // 注意这里如果 start == end，会找不到结果
                        // 但是一开头检查了这种情况，所以这里写在这里
                        if (nx == endx && ny == endy) return step;
                        q.emplace(nx, ny);
                        vis[nx][ny] = true;
                    }
                }
                ++step;
            }
            return -1;
        };
        int res = 0;
        int cx = 0, cy = 0;
        for (int i = 0; i < tree.size(); ++i) {
            int d = bfs(cx, cy, tree[i].first, tree[i].second);
            if (d == -1) return -1;
            res += d;
            // 这里用到了一个小技巧，把比较合并在一个 for 循环
            cx = tree[i].first;
            cy = tree[i].second;
        }
        return res;
    }
};
// @lc code=end

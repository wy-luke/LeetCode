// @lc code=start
/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
class Solution {
public:
    // 并查集
    vector<int> parent;
    int find(int p) {
        if (parent[p] != p) {
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }

    void unite(int p, int q) {
        parent[find(p)] = parent[find(q)];
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    // 求两点的曼哈顿距离
    int getDis(int sx, int sy, int ex, int ey) {
        return abs(ex - sx) + abs(ey - sy);
    }

    int cutOffTree(vector<vector<int>> &forest) {
        // 方向数组
        int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};

        int m = forest.size();
        int n = forest[0].size();
        // 初始化并查集
        parent.reserve(m * n);
        for (int i = 0; i < m * n; ++i) {
            parent.emplace_back(i);
        }
        // 获取全部的树
        vector<pair<int, int>> trees;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 把树加到数组
                if (forest[i][j] > 1) trees.emplace_back(i, j);
                // 开始并查集连通，如果该点为障碍，continue
                if (forest[i][j] == 0) continue;
                // 只检查 左方 和 上方 即可
                for (int k = 0; k < 2; ++k) {
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    // 检查过界 和 障碍
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || forest[nx][ny] == 0) continue;
                    unite(i * n + j, nx * n + ny);
                }
            }
        }
        // 如果有 树 没有和 (0,0) 连通，则返回 -1
        for (const auto &[x, y] : trees) {
            if (!connected(0, x * n + y)) return -1;
        }
        // 排序技巧！！！
        sort(trees.begin(), trees.end(), [&](const auto &a, const auto &b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        // 没有递归，可使用 auto
        function<int(int, int, int, int)> bfs = [&](int startx, int starty, int endx, int endy) -> int {
            if (startx == endx && starty == endy) return 0;
            int step;
            // 记录 (从起点到某点的步数 + 该点到 end 的曼哈顿距离) 和 该点二维坐标
            // 每次优先遍历能够更快到达 end 的点，即小顶堆的 top
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
            pq.emplace(getDis(startx, starty, endx, endy), startx, starty);
            // 记录经过某点时的 步数
            vector<vector<int>> vis(m, vector<int>(n, INT_MAX));
            vis[startx][starty] = 0;
            while (!pq.empty()) {
                // 技巧！！！
                auto [_, curx, cury] = pq.top();
                // 由于不是顺序遍历，所以要取出该点的 步数，+1 为当前步数
                step = vis[curx][cury] + 1;
                pq.pop();
                // 四个方向遍历
                for (int j = 0; j < 4; ++j) {
                    int nx = curx + dir[j][0];
                    int ny = cury + dir[j][1];
                    // 检查过界 和 障碍
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || forest[nx][ny] == 0) continue;
                    // 如果记录的 （经过该点时的步数） 小于等于 当前步数，则跳过，无需继续
                    // 否则可以继续遍历该点，更新结果
                    if (vis[nx][ny] <= step) continue;
                    // 注意这里如果 start == end，会找不到结果
                    // 但是一开头检查了这种情况，所以这里写在这里
                    if (nx == endx && ny == endy) return step;
                    pq.emplace(step + getDis(nx, ny, endx, endy), nx, ny);
                    vis[nx][ny] = step;
                }
            }
            return -1;
        };
        int res = 0;
        int cx = 0, cy = 0;
        for (int i = 0; i < trees.size(); ++i) {
            int d = bfs(cx, cy, trees[i].first, trees[i].second);
            if (d == -1) return -1;
            res += d;
            // 这里用到了一个小技巧，把比较合并在一个 for 循环
            cx = trees[i].first;
            cy = trees[i].second;
        }
        return res;
    }
};
// @lc code=end

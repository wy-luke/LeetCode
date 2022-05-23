/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
class Solution {
public:
    // 求两点的曼哈顿距离
    int getDis(int sx, int sy, int ex, int ey) {
        return abs(ex - sx) + abs(ey - sy);
    }

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
        function<int(int, int, int, int)> astar = [&](int startx, int starty, int endx, int endy) -> int {
            if (startx == endx && starty == endy) return 0;
            int step;
            // 记录 (从起点到某点的步数 + 该点到 end 的曼哈顿距离) 和 该点二维坐标
            // 每次优先遍历能够更快到达 end 的点，即小顶堆的 top
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
            pq.emplace(getDis(startx, starty, endx, endy), startx, starty);
            // 记录经过某点时的 步数，以该点二维坐标转化成的一维坐标为 key，步数为 value
            map<int, int> mp;
            mp[startx * n + starty] = 0;
            while (!pq.empty()) {
                // 技巧！！！
                auto [_, curx, cury] = pq.top();
                // 由于不是顺序遍历，所以要取出该点的 步数
                step = mp[curx * n + cury] + 1;
                pq.pop();
                // 四个方向遍历
                for (int j = 0; j < 4; ++j) {
                    int nx = curx + dir[j][0];
                    int ny = cury + dir[j][1];
                    // 检查过界 和 障碍
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || forest[nx][ny] == 0) continue;
                    // 如果记录的 （经过该点时的步数） 小于等于 当前步数，则跳过，无需继续
                    // 否则可以继续遍历该点，更新结果
                    // 注意要先检查是否存在！！！否则直接访问不存在的值，会直接插入 0
                    if (mp.count(nx * n + ny) != 0 && mp[nx * n + ny] <= step) continue;
                    // 注意这里如果 start == end，会找不到结果
                    // 但是一开头检查了这种情况，所以这里写在这里
                    if (nx == endx && ny == endy) return step;
                    pq.emplace(step + getDis(nx, ny, endx, endy), nx, ny);
                    mp[nx * n + ny] = step;
                }
            }
            return -1;
        };
        int res = 0;
        int cx = 0, cy = 0;
        for (int i = 0; i < tree.size(); ++i) {
            int d = astar(cx, cy, tree[i].first, tree[i].second);
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

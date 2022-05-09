/*
 * @lc app=leetcode.cn id=2242 lang=cpp
 *
 * [2242] 节点序列的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumScore(vector<int> &scores, vector<vector<int>> &edges) {
        int n = scores.size();
        vector<vector<int>> v(n);
        // 邻接表建图
        for (auto &edge : edges) {
            v[edge[0]].emplace_back(edge[1]);
            v[edge[1]].emplace_back(edge[0]);
        }
        // 按 score 排序
        for (auto &i : v) {
            sort(i.begin(), i.end(), [&](const int a, const int b) { return scores[a] > scores[b]; });
        }
        int res = -1;
        // 遍历边，使这个边为中间的边， a-x-y-b 即 x y 的边
        for (auto &edge : edges) {
            int x = edge[0], y = edge[1];
            // 最多只取邻接表中前三个
            for (int i = 0; i < min(3, (int)v[x].size()); ++i) {
                for (int j = 0; j < min(3, (int)v[y].size()); ++j) {
                    if (v[x][i] != y && v[x][i] != v[y][j] && x != v[y][j]) {
                        res = max(res, scores[x] + scores[y] + scores[v[x][i]] + scores[v[y][j]]);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

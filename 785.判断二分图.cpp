/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
private:
    vector<bool> visited;
    vector<bool> color;
    bool res = true;

public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        visited.resize(n);
        color.resize(n);
        for (int v = 0; v < n; ++v) {
            if (!visited[v]) bfs(graph, v);
        }
        return res;
    }

    void bfs(vector<vector<int>> &graph, int start) {
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty() && res) {
            int v = q.front();
            q.pop();
            for (int w : graph[v]) {
                if (!visited[w]) {
                    visited[w] = true;
                    color[w] = !color[v];
                    q.push(w);
                } else {
                    if (color[w] == color[v]) {
                        res = false;
                        break;
                    }
                }
            }
        }
    }
};
// @lc code=end

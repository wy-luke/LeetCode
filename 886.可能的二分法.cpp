/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
class Solution {
private:
    bool res = true;
    // -1 和 1 表示遍历过的不同颜色，0 表示未遍历过
    vector<int> visited;

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        vector<vector<int>> graph;
        graph.resize(n + 1);
        for (vector<int> v : dislikes) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        visited.resize(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            if (visited[i] == 0) bfs(graph, i);
        }
        return res;
    }

    void bfs(vector<vector<int>> &graph, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while (!q.empty() && res) {
            int v = q.front();
            q.pop();
            for (int w : graph[v]) {
                if (visited[w] != 0) {
                    if (visited[w] == visited[v]) {
                        res = false;
                        break;
                    }
                } else {
                    visited[w] = -visited[v];
                    q.push(w);
                }
            }
        }
    }
};
// @lc code=end

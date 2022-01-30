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
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) traverse(graph, i);
        }
        return res;
    }

    void traverse(vector<vector<int>> &graph, int i) {
        if (!res) return;

        visited[i] = true;
        for (int node : graph[i]) {
            if (visited[node]) {
                if (color[node] == color[i]) res = false;
            } else {
                color[node] = !color[i];
                traverse(graph, node);
            }
        }
    }
};
// @lc code=end

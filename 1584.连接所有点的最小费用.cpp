/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
struct Edge {
    int to;
    int len;
};

struct Cmp {
    bool operator()(Edge &a, Edge &b) {
        return a.len > b.len;
    }
};

class Prim {
private:
    vector<bool> visited;
    vector<vector<Edge>> graph;
    priority_queue<Edge, vector<Edge>, Cmp> pq;

public:
    int res;

    void cut(int n) {
        for (auto edge : graph[n]) {
            if (visited[edge.to]) continue;
            pq.emplace(edge);
        }
    }

    Prim(vector<vector<Edge>> graphParameter) {
        graph = graphParameter;
        int n = graph.size();

        visited.resize(n);

        cut(0);
        visited[0] = true;

        res = 0;
        while (!pq.empty()) {
            Edge edge = pq.top();
            pq.pop();

            if (visited[edge.to]) continue;

            visited[edge.to] = true;
            res += edge.len;
            cut(edge.to);
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();

        // 建图
        vector<vector<Edge>> graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int length = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].push_back({j, length});
                graph[j].push_back({i, length});
            }
        }

        Prim prim(graph);

        return prim.res;
    }
};
// @lc code=end

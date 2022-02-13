/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
class UF {
    vector<int> parent;
    vector<int> size;

public:
    UF(int n) {
        size.resize(n, 1);
        parent.reserve(n);
        for (int i = 0; i < n; ++i) {
            parent.emplace_back(i);
        }
    }

    void unite(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
        } else {
            parent[rootQ] = rootP;
        }
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }
};

struct Edge {
    int p1;
    int p2;
    int len;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();

        vector<Edge> edges;
        edges.reserve(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                Edge edge = {i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])};
                edges.emplace_back(edge);
            }
        }

        sort(edges.begin(), edges.end(),
             [](const auto &a, const auto &b) -> bool {
                 return a.len < b.len;
             });

        UF uf(n);
        int res = 0, num = 1;
        for (auto i : edges) {
            if (uf.connected(i.p1, i.p2)) continue;

            uf.unite(i.p1, i.p2);
            res += i.len;
            ++num;
            if (num == n) break;
        }
        return res;
    }
};
// @lc code=end

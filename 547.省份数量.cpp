/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class UF {
private:
    vector<int> parent;
    int count;

public:
    UF(int n) {
        parent.reserve(n);
        for (int i = 0; i < n; ++i) {
            parent.emplace_back(i);
        }
        count = n;
    }

    void unite(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        parent[rootP] = rootQ;
        --count;
    }

    int find(int p) {
        while (parent[p] != p) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        UF uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) uf.unite(i, j);
            }
        }
        return uf.getCount();
    }
};

// @lc code=end

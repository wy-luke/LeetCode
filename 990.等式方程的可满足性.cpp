/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution {
public:
    class UF {
        vector<int> parent;
        int count;
        vector<int> size;

    public:
        UF(int n) {
            count = n;
            parent.reserve(n);
            size.resize(n, 1);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        void unite(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);

            if (rootP == rootQ) return;

            if (size[rootP] < size[rootQ]) {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            } else {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            }
            count--;
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

    bool equationsPossible(vector<string> &equations) {
        UF uf(26);
        for (string i : equations) {
            if (i[1] == '=') uf.unite(i[0] - 'a', i[3] - 'a');
        }

        for (string i : equations) {
            if (i[1] == '!') {
                if (uf.connected(i[0] - 'a', i[3] - 'a')) return false;
            }
        }
        return true;
    }
};
// @lc code=end

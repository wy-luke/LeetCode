/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
private:
    class UF {
    private:
        int count;
        vector<int> parent;
        vector<int> size;

    public:
        UF(int n) {
            count = n;
            parent.reserve(n);
            size.reserve(n);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        void union2(int p, int q) {
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
            --count;
        }

        bool connected(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            // 处于同一棵树上的节点，相互连通
            return rootP == rootQ;
        }

        int getCount() {
            return count;
        }
    };

public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0) return;

        int m = board.size();
        int n = board[0].size();
        UF uf(m * n + 1);
        int dummy = m * n;

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') uf.union2(i * n, dummy);
            if (board[i][n - 1] == 'O') uf.union2(i * n + n - 1, dummy);
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') uf.union2(j, dummy);
            if (board[m - 1][j] == 'O') uf.union2((m - 1) * n + j, dummy);
        }

        int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (board[i][j] == 'O') {
                    for (int k = 0; k < 4; ++k) {
                        int x = i + d[k][0], y = j + d[k][1];
                        if (board[x][y] == 'O') uf.union2(i * n + j, x * n + y);
                    }
                }
            }
        }

        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (!uf.connected(i * n + j, dummy)) {
                    board[i][j] = 'X';
                }
            }
        }
    };
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    int m, n;

    void solve(vector<vector<char>> &board) {
        m = board.size();
        n = board[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') q.emplace(i, 0);
            if (board[i][n - 1] == 'O') q.emplace(i, n - 1);
        }

        for (int j = 1; j < n - 1; ++j) {
            if (board[0][j] == 'O') q.emplace(0, j);
            if (board[m - 1][j] == 'O') q.emplace(m - 1, j);
        }

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                int curx = q.front().first;
                int cury = q.front().second;
                q.pop();
                if (curx < 0 || curx >= m || cury < 0 || cury >= n || board[curx][cury] != 'O') continue;

                board[curx][cury] = 'A';

                q.emplace(curx + 1, cury);
                q.emplace(curx - 1, cury);
                q.emplace(curx, cury + 1);
                q.emplace(curx, cury - 1);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> res;

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    void backtrack(vector<string> board, int row) {
        if (board.size() == row) {
            res.emplace_back(board);
            return;
        }

        for (int i = 0; i < board.size(); ++i) {
            if (!isValid(board, row, i)) continue;
            // 选择
            board[row][i] = 'Q';
            backtrack(board, row + 1);
            // 回溯
            board[row][i] = '.';
        }
    }

    bool isValid(vector<string> &board, int row, int col) {
        // 检查上方
        for (int i = row - 1; i >= 0; --i) {
            if (board[i][col] == 'Q') return false;
        }
        // 检查左上方
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }
        // 检查右上方
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};
// @lc code=end

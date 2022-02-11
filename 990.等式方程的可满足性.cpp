/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution {
    int dp[26][26];
    bool notEqual[26 * 26];
    vector<bool> visited;

public:
    bool dfs(int x, int y) {
        if (notEqual[x * 26 + y] || visited[x * 26 + y]) return false;

        if (dp[x][y] == 1) return true;

        visited[x * 26 + y] = true;
        for (int i = 0; i < 26; ++i) {
            if (dp[x][i] == 1) {
                if (dfs(i, y)) return true;
            }
        }
        notEqual[x * 26 + y] = true;
        return false;
    }

    bool equationsPossible(vector<string> &equations) {
        visited.resize(26 * 26);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }

        for (string i : equations) {
            if (i[1] == '=') {
                dp[i[0] - 'a'][i[3] - 'a'] = 1;
                dp[i[3] - 'a'][i[0] - 'a'] = 1;
            }
        }

        for (string i : equations) {
            if (i[1] == '!') {
                if (dfs(i[0] - 'a', i[3] - 'a')) return false;
                fill(visited.begin(), visited.end(), false);
            }
        }
        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution {
    // 用于记录等式，1 为 ==， 0 为 !=，可改为链表储存
    int dp[26][26];
    // 记录两个数是否相等，相当于一个备忘录
    bool notEqual[26 * 26];
    // 记录每次搜索的路径，防止回头
    vector<bool> visited;

public:
    bool bfs(int x, int y) {
        queue<pair<int, int>> q;
        q.emplace(x, y);
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            // 如果记录有 (x, y) 不相等或已经路过 (x, y)，则返回 false
            if (notEqual[x * 26 + y] || visited[x * 26 + y]) continue;

            // 如果 (x, y) 相等则返回 true
            if (dp[x][y] == 1) return true;

            visited[x * 26 + y] = true;

            for (int i = 0; i < 26; ++i) {
                if (dp[x][i] == 1) q.emplace(i, y);
            }
        }
        notEqual[x * 26 + y] = true;
        notEqual[y * 26 + x] = true;
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
                if (bfs(i[0] - 'a', i[3] - 'a')) return false;
                // 每次搜索是独立的，所以每次搜索后需要把 visited 还原
                fill(visited.begin(), visited.end(), false);
            }
        }
        return true;
    }
};
// @lc code=end

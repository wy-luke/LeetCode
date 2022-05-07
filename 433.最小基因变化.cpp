/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string> &bank) {
        if (start == end)
            return 0;
        else if (bank.size() == 0)
            return -1;

        int n = bank.size();
        int m = start.size();
        // 预处理 构造邻接表
        vector<vector<int>> adj(n);
        // 找到 endIndex
        int endIndex = -1;
        for (int i = 0; i < n; ++i) {
            if (bank[i] == end) endIndex = i;

            for (int j = i + 1; j < n; ++j) {
                int diffTimes = 0;
                for (int k = 0; k < m; ++k) {
                    if (bank[i][k] != bank[j][k]) diffTimes++;
                    if (diffTimes > 1) break;
                }
                if (diffTimes == 1) {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }
        if (endIndex == -1) return -1;

        // 开始 bfs
        queue<int> q;
        vector<bool> visited(n);
        int step = 1;
        // 加入 start
        for (int i = 0; i < n; ++i) {
            int diffTimes = 0;
            for (int k = 0; k < m; ++k) {
                if (start[k] != bank[i][k]) diffTimes++;
                if (diffTimes > 1) break;
            }
            if (diffTimes == 1) {
                q.emplace(i);
                visited[i] = true;
            }
        }
        // 开始 bfs 主体
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int index = q.front();
                q.pop();
                if (index == endIndex) return step;
                for (int &next : adj[index]) {
                    if (visited[next] == false) {
                        q.emplace(next);
                        visited[next] = true;
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
// @lc code=end

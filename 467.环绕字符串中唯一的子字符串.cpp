/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// @lc code=start
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        if (n == 1) return 1;
        vector<int> vis(26);
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && (p[i] - p[i - 1] == 1 || p[i] - p[i - 1] == -25)) {
                cnt++;
            } else {
                cnt = 1;
            }
            vis[p[i] - 'a'] = max(vis[p[i] - 'a'], cnt);
        }
        return accumulate(vis.begin(), vis.end(), 0);
    }
};
// @lc code=end

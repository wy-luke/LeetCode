/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();
        vector<int> cnts(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int cnt = 1;
            for (int j = i + 1; j < n; ++j) {
                if (pairs[j][0] > pairs[i][1]) {
                    cnt = max(cnt, 1 + cnts[j]);
                }
            }
            ans = max(ans, cnt);
            cnts[i] = cnt;
        }
        return ans;
    }
};
// @lc code=end

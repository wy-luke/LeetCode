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

        int n = pairs.size(), ans = 1;
        vector<int> cnts(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; --j) {
                if (pairs[j][1] < pairs[i][0]) {
                    cnts[i] = 1 + cnts[j];
                    break;
                }
            }
            ans = max(ans, cnts[i]);
        }
        return ans;
    }
};
// @lc code=end

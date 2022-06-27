/*
 * @lc app=leetcode.cn id=522 lang=cpp
 *
 * [522] 最长特殊序列 II
 */

// @lc code=start
class Solution {
public:
    int findLUSlength(vector<string> &strs) {
        int n = strs.size();
        int res = -1;
        // 检查 strs[i] 是否为 strs[j] 的子序列
        // 如果全不是，则 strs[i] 为特殊序列，更新答案
        for (int i = 0; i < n; ++i) {
            bool check = true;
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                int l = 0, r = 0;
                while (l < strs[i].size() && r < strs[j].size()) {
                    if (strs[i][l] == strs[j][r]) ++l;
                    ++r;
                }
                if (l == strs[i].size()) {
                    check = false;
                    break;
                }
            }
            if (check) res = max(res, (int)strs[i].size());
        }
        return res;
    }
};
// @lc code=end

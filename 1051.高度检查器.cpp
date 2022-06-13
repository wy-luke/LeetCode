/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc code=start
class Solution {
public:
    int heightChecker(vector<int> &heights) {
        auto tmp = heights;
        sort(heights.begin(), heights.end());
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (tmp[i] != heights[i]) ++res;
        }
        return res;
    }
};
// @lc code=end

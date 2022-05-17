/*
 * @lc app=leetcode.cn id=2274 lang=cpp
 *
 * [2274] 不含特殊楼层的最大连续楼层数
 */

// @lc code=start
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int> &special) {
        // 加入 top+1，简化代码逻辑
        special.emplace_back(top + 1);
        sort(special.begin(), special.end());
        int left = bottom;
        int res = 0;
        for (int i = 0; i < special.size(); ++i) {
            res = max(res, special[i] - left);
            left = special[i] + 1;
        }
        return res;
    }
};
// @lc code=end

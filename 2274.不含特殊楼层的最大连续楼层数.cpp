/*
 * @lc app=leetcode.cn id=2274 lang=cpp
 *
 * [2274] 不含特殊楼层的最大连续楼层数
 */

// @lc code=start
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int> &special) {
        sort(special.begin(), special.end());
        int left = bottom, index = 0;
        int res = 0;
        while (index < special.size()) {
            res = max(res, special[index] - left);
            left = special[index] + 1;
            index++;
        }
        res = max(res, top - left + 1);
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2240 lang=cpp
 *
 * [2240] 买钢笔和铅笔的方案数
 */

// @lc code=start
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int c1 = 0;
        long long res = 0;

        while (c1 <= total) {
            res += (total - c1) / cost2 + 1;
            c1 += cost1;
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        vector<int> cnt(100);
        int res = 0;
        for (const auto &dominoe : dominoes) {
            // 技巧，把两个数转换为一个二位数
            int num;
            if (dominoe[0] < dominoe[1]) {
                num = dominoe[0] * 10 + dominoe[1];
            } else {
                num = dominoe[1] * 10 + dominoe[0];
            }
            // 技巧，求组合数转换为每次累加！！！
            res += cnt[num];
            cnt[num]++;
        }
        return res;
    }
};
// @lc code=end

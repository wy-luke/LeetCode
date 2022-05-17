/*
 * @lc app=leetcode.cn id=2275 lang=cpp
 *
 * [2275] 按位与结果大于零的最长组合
 */

// @lc code=start
class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        // 要使两个数按位与大于 0，保证至少有一个位 按位与 结果不为 0 即可
        int res = 0;
        // 1<<2 二进制表示为 100 即第三位是 1，后面为 0
        // 2^23 < 10^7 < 2^24，对于 1<<24 二进制表示是 1000....，即第 25 位是 1，其余为 0
        // 对于所有 candidate 小于 1<<24，需要退一位，所以第 25 位肯定是 0，所以无需比较第 25 位
        // 综上，枚举比特位从 0 到 23 即可
        for (int i = 0; i < 24; ++i) {
            int cnt = 0;
            for (int j = 0; j < candidates.size(); ++j) {
                // & 运算要用括号包起来！！！
                if ((candidates[j] & (1 << i)) > 0) cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end

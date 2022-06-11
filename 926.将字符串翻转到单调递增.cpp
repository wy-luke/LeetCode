/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // cnt0 为单调递增且以 0 结尾时的最小翻转次数，cnt1 为以 1 结尾
        int cnt0 = 0, cnt1 = 0;
        for (char c : s) {
            if (c == '0') {
                // 当前位为 0 时
                // 以 0 结尾，前一位必须是 0，所以 cnt0 等于上一位 cnt0
                // 以 1 结尾，前一位可以是 0 或 1，取小的，并且当前位要翻转为 1，所以 +1
                cnt1 = min(cnt0, cnt1) + 1;
            } else {
                // 当前位为 1 时
                // 以 1 结尾，前一位可以是 0 或 1，取小的，当前位不需翻转
                // 因为这里要用到 cnt0，所以先更新 cnt1
                cnt1 = min(cnt0, cnt1);
                // 以 0 结尾，前一位必须是 0，且当前位需要翻转为 0，所以 +1
                cnt0 = cnt0 + 1;
            }
        }
        // 返回到最后一位时，以 0 或 1 结尾中翻转次数小的
        return min(cnt0, cnt1);
    }
};
// @lc code=end

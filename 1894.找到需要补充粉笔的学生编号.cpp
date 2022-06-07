/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */

// @lc code=start
class Solution {
public:
    int chalkReplacer(vector<int> &chalk, int k) {
        int n = chalk.size();
        if (chalk[0] > k) return 0;
        // 前缀和
        for (int i = 1; i < n; ++i) {
            chalk[i] += chalk[i - 1];
            // 如果大于 k，直接返回 i，同时保证了不会溢出
            if (chalk[i] > k) return i;
        }
        k %= chalk[n - 1];
        if (k == 0) return 0;
        // 二分，upper_bound
        int l = 0, r = n;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (chalk[mid] <= k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

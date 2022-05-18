/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        // 开始二分
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            int cnt = (mid / n) * n;
            for (int i = mid / n + 1; i <= m; ++i) {
                cnt += mid / i;
            }
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

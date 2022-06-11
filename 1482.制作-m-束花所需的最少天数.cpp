/*
 * @lc app=leetcode.cn id=1482 lang=cpp
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) return -1;
        auto check = [&](int d) -> int {
            int res = 0, cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (bloomDay[i] > d) {
                    cnt = 0;
                    continue;
                }
                ++cnt;
                if (cnt == k) {
                    ++res;
                    cnt = 0;
                }
            }
            return res;
        };

        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid) < m) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1552 lang=cpp
 *
 * [1552] 两球之间的磁力
 */

// @lc code=start
class Solution {
public:
    // 找到某个最小磁力时，最多能放的球的个数
    int check(vector<int> &psn, int x) {
        int pre = psn[0], cnt = 1;
        for (int i = 1; i < psn.size(); ++i) {
            if (psn[i] - pre >= x) {
                pre = psn[i];
                cnt++;
            }
        }
        return cnt;
    }

    int maxDistance(vector<int> &position, int m) {
        sort(position.begin(), position.end());
        // 随着最小磁力的增大，能放置球的个数会减少
        // 所以可以利用二分，找到能放置 m 个球时的最大 最小磁力
        int l = 1, r = position.back() - position[0];
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(position, mid) >= m) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};
// @lc code=end

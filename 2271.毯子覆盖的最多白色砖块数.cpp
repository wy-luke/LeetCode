/*
 * @lc app=leetcode.cn id=2271 lang=cpp
 *
 * [2271] 毯子覆盖的最多白色砖块数
 */

// @lc code=start
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        // 前缀和数组
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + tiles[i][1] - tiles[i][0] + 1;
        }
        int res = 0;
        // 利用贪心思想，枚举每个 tile 的起点即可
        for (int i = 0; i < n; ++i) {
            int target = tiles[i][0] + carpetLen - 1;
            // 二分
            int l = i, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                // 找到第一个 大于 target 的，即 upper_bound
                if (tiles[mid][0] <= target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (tiles[l - 1][1] <= target) {
                res = max(res, pre[l] - pre[i]);
            } else {
                // l - 1 < i 时，前缀和数组失效，pre[l - 1] - pre[i] 会得到负数
                if (l - 1 >= i) {
                    res = max(res, pre[l - 1] - pre[i] + target - tiles[l - 1][0] + 1);
                } else {
                    // 此时 l == i，直接求结果即可
                    res = max(res, target - tiles[l - 1][0] + 1);
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int l = i, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                // 由前缀和获得 [i,j] 为 pre[j+1]-pre[i]
                if (pre[mid + 1] - pre[i] >= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l != n) res = min(res, l - i + 1);
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

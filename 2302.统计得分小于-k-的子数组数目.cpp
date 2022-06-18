/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int> &nums, long long k) {
        int n = nums.size();
        long long res = 0;
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
        for (int i = 0; i < n; ++i) {
            int l = i, r = n;
            while (l < r) {
                int mid = l + ((r - l) >> 1);
                if ((pre[mid + 1] - pre[i]) * (mid - i + 1) < k) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            // l 为第一个不符合条件的下标，l-i 即为符合的个数
            res += l - i;
        }
        return res;
    }
};
// @lc code=end

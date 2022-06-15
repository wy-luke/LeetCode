/*
 * @lc app=leetcode.cn id=1712 lang=cpp
 *
 * [1712] 将数组分成三个子数组的方案数
 */

// @lc code=start
class Solution {
public:
    int waysToSplit(vector<int> &nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
        int res = 0;
        // 枚举中间区间的左端点，然后二分查找右端点
        for (int i = 1; i <= nums.size() - 2; ++i) {
            // 先找到第一个满足 区间和>=左边区间和 的下标 l1
            int l1 = i, r1 = nums.size() - 2;
            while (l1 <= r1) {
                int mid = l1 + ((r1 - l1) >> 1);
                if (pre[mid + 1] - pre[i] < pre[i]) {
                    l1 = mid + 1;
                } else {
                    r1 = mid - 1;
                }
            }
            // 再找到最后一个满足 区间和<=右边区间和 的下标 l2-1
            int l2 = i, r2 = nums.size() - 2;
            while (l2 <= r2) {
                int mid = l2 + ((r2 - l2) >> 1);
                if (pre[mid + 1] - pre[i] <= pre[n] - pre[mid + 1]) {
                    l2 = mid + 1;
                } else {
                    r2 = mid - 1;
                }
            }
            // 包含组合个数，即数字的个数，为 (l2-1)-l1+1 即 l2-l1，去除负数情况
            res = (res + max(0, l2 - l1)) % MOD;
        }
        return res;
    }
};
// @lc code=end

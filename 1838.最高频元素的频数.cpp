/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int> &nums, vector<long long> &pre, int t, int k) {
        int n = nums.size();
        for (int i = 0; i < n - t + 1; ++i) {
            if ((long long)t * nums[i + t - 1] - (pre[i + t] - pre[i]) <= k) return true;
        }
        return false;
    }
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
        int l = 2, r = n;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(nums, pre, mid, k)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};
// @lc code=end

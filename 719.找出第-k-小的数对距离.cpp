/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 K 小的数对距离
 */

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums.back() - nums[0];
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                // 找到以 i 开始，绝对值差 小于等于 mid 的数对的个数
                int idx = upper_bound(nums.begin() + i, nums.end(), nums[i] + mid) - nums.begin();
                cnt += idx - i-1;
            }
            // 找到第一个 cnt 大于等于 k 的，即为所求
            if (cnt < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1818 lang=cpp
 *
 * [1818] 绝对差值和
 */

// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
        vector<int> nums = nums1;
        // 排序，便于从 nums1 中找到最接近 nums2 中某数的数字（二分）
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 记录替换字符后，绝对差值和 的最大减少量
        int reduce = INT_MIN;
        for (int i = 0; i < n; ++i) {
            // 找到最接近 nums2[i] 的数字的下标，因为是绝对值接近，所以要比较 idx 和 idx-1
            // idx=0 或 idx=n 时，边界，只比较一侧即可
            int idx = lower_bound(nums.begin(), nums.end(), nums2[i]) - nums.begin();
            if (idx == 0) {
                reduce = max(reduce, abs(nums2[i] - nums1[i]) - abs(nums2[i] - nums[0]));
            } else if (idx == n) {
                reduce = max(reduce, abs(nums2[i] - nums1[i]) - abs(nums2[i] - nums[n - 1]));
            } else {
                reduce = max(reduce, abs(nums2[i] - nums1[i]) - min(abs(nums2[i] - nums[idx]), abs(nums2[i] - nums[idx - 1])));
            }
        }
        int res = -reduce;
        for (int i = 0; i < n; ++i) {
            res = (res + abs(nums2[i] - nums1[i])) % MOD;
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n - 2; ++i) {
            int k = i + 2;
            for (int j = i + 1; j < n - 1; ++j) {
                int target = nums[i] + nums[j];
                auto it = lower_bound(nums.begin() + k, nums.end(), target);
                int k = (int)(it - nums.begin());
                res += max(0, k - j - 1);
            }
        }
        return res;
    }
};
// @lc code=end

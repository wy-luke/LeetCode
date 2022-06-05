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
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int target = nums[i] + nums[j];
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), target);
                res += (int)(it - nums.begin()) - j - 1;
            }
        }
        return res;
    }
};
// @lc code=end

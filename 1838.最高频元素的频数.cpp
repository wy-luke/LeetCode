/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */

// @lc code=start
class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 1;
        // 滑窗, [l,r)，题目原因，初始区间包含第一个元素
        int l = 0, r = 1;
        // 全部化为窗口内最后一个数字需要的操作数
        long long sum = 0;
        while (r < n) {
            int num1 = nums[r++];
            sum += (long long)(num1 - nums[r - 2]) * (r - l - 1);

            while (sum > k) {
                int num2 = nums[l++];
                sum -= (nums[r - 1] - num2);
            }
            res = max(res, r - l);
        }
        return res;
    }
};
// @lc code=end

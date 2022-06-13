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
        // 滑窗, [l,r)，题目原因，从区间内包含第一个元素开始搜索
        int l = 0, r = 1;
        // 窗口内数字和
        long long sum = nums[0];
        // 全部化为窗口内最后一个数字需要的操作数
        int cnt = 0;
        while (r < n) {
            int num1 = nums[r++];
            sum += num1;
            cnt = (long long)(r - l) * nums[r - 1] - sum;

            while (cnt > k) {
                int num2 = nums[l++];
                sum -= num2;
                cnt = (long long)(r - l) * nums[r - 1] - sum;
            }
            res = max(res, r - l);
        }
        return res;
    }
};
// @lc code=end

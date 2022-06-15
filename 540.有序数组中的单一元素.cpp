/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        // l、r 分别为第一个偶数和最后一个偶数
        int l = 0, r = nums.size() - 1;
        // 由于存在过界问题，可通过控制区间开闭处理边界情况
        // 我们在 [0, size-1) 偶数区间搜索，mid 取值最大为 size-3，即倒数第二个偶数，mid+1 不再会过界
        // 同时，若区间内最后一个元素，即 size-3，nums 倒数第二个偶数，依然成对时，就会返回 size-1
        // size-1 即类似于返回 nums.end()，即区间外的第一个元素，满足题意
        // 同理，可在 [0, size-3] 偶数区间内搜索，mid 取值最大为 size-3，依然成对时，返回 size-1
        // 注意区间开闭影响 r 的更新取值
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            mid -= mid & 1;
            // 防止过界，且 mid==nums.size()-1 时归为 else
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
// @lc code=end

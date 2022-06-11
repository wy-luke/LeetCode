/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size() - 1;
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            // cnt 为 nums 中 小于等于 某数 x(这里为 mid) 的个数
            // 设重复数为 target，若 x<target，则 cnt<=x，若 x>target，则 cnt>x
            int cnt = 0;
            for (int num : nums) {
                cnt += num <= mid;
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
// @lc code=end

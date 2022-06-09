/*
 * @lc app=leetcode.cn id=1760 lang=cpp
 *
 * [1760] 袋子里最少数目的球
 */

// @lc code=start
class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            int times = 0;
            for (int num : nums) {
                times += (num - 1) / mid;
            }
            if (times <= maxOperations) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] % 2 == 0) {
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                ++i;
            }
            ++j;
        }
        return nums;
    }
};
// @lc code=end

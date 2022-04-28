/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < j && nums[i] % 2 == 0) {
                ++i;
            }
            while (i < j && nums[j] % 2 != 0) {
                --j;
            }
            swap(nums[i++], nums[j--]);
        }
        return nums;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int i = 0, j = 1;
        while (j < n) {
            if (nums[j] != nums[i]) {
                nums[i + 1] = nums[j];
                ++i;
            }
            ++j;
        }
        return i + 1;
    }
};
// @lc code=end

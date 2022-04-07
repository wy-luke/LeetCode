/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int n = nums.size();
        if (n == 0) return 0;

        int i = 0, j = n - 1;
        while (i <= j) {
            if (nums[i] == val) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                --j;
            } else {
                ++i;
            }
        }
        return i + 1;
    }
};
// @lc code=end

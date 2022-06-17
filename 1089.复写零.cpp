/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
public:
    void shiftRight(vector<int> &arr, int target) {
        int pre = 0, cur;
        for (int i = target + 1; i < arr.size(); ++i) {
            cur = arr[i];
            arr[i] = pre;
            pre = cur;
        }
    }

    void duplicateZeros(vector<int> &arr) {
        for (int i = 0; i < arr.size(); ++i) {
            // 每找到一个 0，向后面加一个 0，并且右移后面的所有元素，注意 i 需要 +2
            if (arr[i] == 0) shiftRight(arr, i++);
        }
    }
};
// @lc code=end

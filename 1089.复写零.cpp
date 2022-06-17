/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = 0;
        while (j < n) {
            if (arr[i] == 0) ++j;
            ++j;
            ++i;
        }
        // 此时按题目复写 0 后，已经可以把数组填满，开始回写
        j--;
        i--;
        while (i >= 0) {
            // 避免一开始 j 仍在数组外
            if (j < n) arr[j] = arr[i];
            if (arr[i] == 0 && j > 0) arr[--j] = 0;
            --j;
            --i;
        }
    }
};
// @lc code=end

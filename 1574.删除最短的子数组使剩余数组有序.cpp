/*
 * @lc app=leetcode.cn id=1574 lang=cpp
 *
 * [1574] 删除最短的子数组使剩余数组有序
 */

// @lc code=start
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        // 按题意，非降序即为有序
        int n = arr.size();
        int i = 0, j = n - 1;
        while (i + 1 < n && arr[i] <= arr[i + 1]) ++i; // [0,i] 为有序
        if (i == n - 1) return 0;
        while (j - 1 >= 0 && arr[j] >= arr[j - 1]) --j; // [j,n-1] 为有序
        // 只保留 左边部分 或 右边部分 时，需要删除的长度
        int res = min(n - i - 1, j);
        // 同时保留 左右部分 时，需要删除的长度
        int left = 0, right = j;
        while (left <= i && right <= n - 1) {
            if (arr[left] <= arr[right]) {
                // [0, left] 和 [right, n-1] 有序
                res = min(res, right - left - 1);
                ++left;
            } else {
                ++right;
            }
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = arr.size();
        // 二分
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int idx = (int)(it - arr.begin());
        // 双指针
        int l = idx - 1, r = idx;
        while (r - l - 1 < k) {
            if (l >= 0 && r < n) {
                if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                    l--;
                } else {
                    r++;
                }
            } else if (l < 0) {
                r++;
            } else {
                l--;
            }
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};
// @lc code=end

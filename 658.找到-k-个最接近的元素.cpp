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
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int idx = (int)(it - arr.begin());
        vector<int> res;
        int l = idx - 1, r = idx;
        while (res.size() < k) {
            if (l >= 0 && r < n) {
                if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                    res.emplace_back(arr[l--]);
                } else {
                    res.emplace_back(arr[r++]);
                }
            } else if (l < 0) {
                res.emplace_back(arr[r++]);
            } else {
                res.emplace_back(arr[l--]);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 *
 * [1385] 两个数组间的距离值
 */

// @lc code=start
class Solution {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int res = 0;
        int left = 0;
        for (int i : arr1) {
            int l = bs(left, arr2, i);
            if (l > 0 && abs(i - arr2[l - 1]) <= d) continue;
            if (l < arr2.size() && abs(i - arr2[l]) <= d) continue;
            ++res;
            left = l;
        }
        return res;
    }
    int bs(int l, vector<int> &arr2, int t) {
        int r = arr2.size();
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (arr2[mid] < t) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

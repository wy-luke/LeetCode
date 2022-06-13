/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int bs(vector<int> &citations, int t) {
        int l = 0, r = citations.size();
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (citations[mid] < t) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return citations.size() - l;
    }
    int hIndex(vector<int> &citations) {
        int l = 0, r = citations.back();
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            int cnt = bs(citations, mid);
            if (cnt < mid) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};
// @lc code=end

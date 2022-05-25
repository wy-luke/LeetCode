/*
 * @lc app=leetcode.cn id=2279 lang=cpp
 *
 * [2279] 装满石头的背包的最大数量
 */

// @lc code=start
class Solution {
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> left;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int dif = capacity[i] - rocks[i];
            if (dif == 0) {
                ++res;
            } else {
                left.emplace_back(dif);
            }
        }
        sort(left.begin(), left.end());
        for (auto &l : left) {
            if (additionalRocks >= l) {
                ++res;
                additionalRocks -= l;
            } else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

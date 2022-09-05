/*
 * @lc app=leetcode.cn id=2395 lang=cpp
 *
 * [2395] 和相等的子数组
 */

// @lc code=start
class Solution {
public:
    bool findSubarrays(vector<int> &nums) {
        unordered_set<int> st;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int res = nums[i] + nums[i + 1];
            if (st.count(res)) {
                return true;
            }
            st.emplace(res);
        }
        return false;
    }
};
// @lc code=end

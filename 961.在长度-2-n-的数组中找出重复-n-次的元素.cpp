/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 */

// @lc code=start
class Solution {
public:
    int repeatedNTimes(vector<int> &nums) {
        unordered_set<int> st;
        for (const int &num : nums) {
            if (st.count(num)) return num;
            st.insert(num);
        }
        return -1;
    }
};
// @lc code=end

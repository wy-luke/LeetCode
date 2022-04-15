/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<pair<int, int>> st; // 单调栈，存放 温度值和对应的 index

        for (int i = n - 1; i >= 0; --i) {
            int t = temperatures[i];
            while (!st.empty() && st.top().first <= t) {
                st.pop();
            }
            res[i] = st.empty() ? 0 : st.top().second - i;
            st.emplace(t, i);
        }
        return res;
    }
};
// @lc code=end

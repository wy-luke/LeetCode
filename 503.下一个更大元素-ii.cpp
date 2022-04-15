/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st; // 单调栈

        // 形式上把 nums 数组翻倍，即 nums 后面再跟一个 nums
        // 取值时，可以直接通过 取模 % 获取翻倍数组对应的 index
        for (int i = 2 * n - 1; i >= 0; --i) {
            // 注意这里不可以直接修改 i 否则影响循环！！！
            int j = i % n;
            int num = nums[j];
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            res[j] = st.empty() ? -1 : st.top();
            st.emplace(nums[j]);
        }
        return res;
    }
};
// @lc code=end

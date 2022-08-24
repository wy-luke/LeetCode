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
        vector<int> res(n, -1);
        stack<int> stk; // 单调栈

        // 形式上把 nums 数组翻倍，即 nums 后面再跟一个 nums
        // 取值时，可以直接通过 取模 % 获取翻倍数组对应的 index
        for (int i = 0; i < 2 * n; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                res[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.emplace(i % n);
        }
        return res;
    }
};
// @lc code=end

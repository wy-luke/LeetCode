/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> mp; // 哈希表
        stack<int> st;              // 单调栈
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            mp[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        vector<int> res;
        res.reserve(nums1.size());
        for (int i : nums1) {
            res.emplace_back(mp[i]);
        }
        return res;
    }
};
// @lc code=end

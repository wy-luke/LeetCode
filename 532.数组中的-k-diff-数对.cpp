/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        // k 是定值，所以知道数对的一个数，另一个数是确定的
        // 所以我们只找数对中较小的那个数，放入 res 中
        unordered_set<int> visited;
        unordered_set<int> res;
        for (int num : nums) {
            if (visited.count(num - k)) {
                res.emplace(num - k);
            }
            if (visited.count(num + k)) {
                res.emplace(num);
            }
            visited.emplace(num);
        }
        return res.size();
    }
};
// @lc code=end

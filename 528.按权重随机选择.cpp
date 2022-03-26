/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {
private:
    mt19937 generator;
    uniform_int_distribution<int> dis;
    vector<int> preSum;

public:
    Solution(vector<int> &w) : generator(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(preSum));
    }

    int pickIndex() {
        int x = dis(generator);
        return lower_bound(preSum.begin(), preSum.end(), x) - preSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

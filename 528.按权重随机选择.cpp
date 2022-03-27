/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {
private:
    // // 用于生成随机数
    // mt19937 generator;
    // uniform_int_distribution<int> dis;

    // 前缀和数组
    vector<int> preSum;

public:
    // Solution(vector<int> &w) : generator(random_device()()), dis(1, accumulate(w.begin(), w.end(), 0)) {
    Solution(vector<int> &w) {
        // // 生成前缀和数组
        // partial_sum(w.begin(), w.end(), back_inserter(preSum));

        // 生成前缀和数组
        int n = w.size();
        preSum.reserve(n + 1);
        preSum.emplace_back(0);
        for (int i = 0; i < n; i++) {
            preSum.emplace_back(preSum[i] + w[i]);
        }
    }

    // 二分搜索，左侧边界，即大于等于 target 的最小索引  （右侧边界，小于等于 target 的最大索引）
    int bSearch(int target) {
        int left = 0, right = preSum.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (preSum[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int pickIndex() {
        // // 生成随机数
        // int x = dis(generator);
        // // lower_bound : Returns an iterator pointing to the first element in the range [first, last)
        // // that is not less than (i.e. greater or equal to) value,
        // // or last if no such element is found.
        // return lower_bound(preSum.begin(), preSum.end(), x) - preSum.begin();

        // rand() % max 生成 [0, max) 范围的随机数
        int x = 1 + rand() % (preSum.back()); // 生成 [1, preSum.back()] 范围的随机数
        return bSearch(x) - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

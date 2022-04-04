/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution {
private:
    vector<long> tmp;
    int lb, ub;
    int res = 0;

public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        lb = lower;
        ub = upper;

        int n = nums.size();
        tmp.resize(n + 1);
        // 前缀和数组，区间和可以表述为 preSum[j] - preSum[i] , j > i
        vector<long> preSum;
        preSum.reserve(n + 1);
        preSum.emplace_back(0);
        for (int i = 0; i < n; ++i) {
            preSum.emplace_back(preSum[i] + nums[i]);
        }
        sort(preSum, 0, n);
        return res;
    }

    void sort(vector<long> &preSum, int lo, int hi) {
        if (lo >= hi) return;

        int mid = lo + (hi - lo) / 2;
        sort(preSum, lo, mid);
        sort(preSum, mid + 1, hi);
        merge(preSum, lo, mid, hi);
    }

    void merge(vector<long> &preSum, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; ++i) {
            tmp[i] = preSum[i];
        }

        // 维护区间 [start, end) 内的元素 与 preSum[i] 组成的区间满足要求
        // 把 start 和 end 定义在外面，避免每次循环都要从头遍历，减少时间复杂度
        int start = mid + 1, end = mid + 1;
        for (int i = lo; i <= mid; ++i) {
            while (start <= hi && preSum[start] - preSum[i] < lb) {
                start++;
            }
            while (end <= hi && preSum[end] - preSum[i] <= ub) {
                end++;
            }
            res += end - start;
        }

        int p = lo, q = mid + 1;
        for (int i = lo; i <= hi; ++i) {
            if (p == mid + 1) {
                preSum[i] = tmp[q++];
            } else if (q == hi + 1) {
                preSum[i] = tmp[p++];
            } else if (tmp[p] > tmp[q]) {
                preSum[i] = tmp[q++];
            } else {
                preSum[i] = tmp[p++];
            }
        }
    }
};
// @lc code=end

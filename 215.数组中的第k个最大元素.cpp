/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        // 经过快速排序（升序），第 k 大元素的 index 为 n - k
        k = n - k;
        shuffle(nums);
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int p = partition(nums, lo, hi);
            if (p < k) {
                lo = p + 1;
            } else if (p > k) {
                hi = p - 1;
            } else {
                return nums[p];
            }
        }
        return -1;
    }

    int partition(vector<int> &nums, int lo, int hi) {
        int pivot = nums[lo];

        // 维护区间 [lo, i) <= pivot, (j, hi] > pivot
        // 初始化 [lo, i) 仅包含 lo 元素，(j, hi] 为空
        int i = lo + 1, j = hi;
        // 当 i > j 时结束循环，以保证区间 [lo, hi] 都被覆盖
        while (i <= j) {
            while (i < hi && nums[i] <= pivot) {
                ++i;
            }
            while (j > lo && nums[j] > pivot) {
                --j;
            }

            if (i >= j) break;
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        return j;
    }

    void shuffle(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // 生成 [i, n-1]范围的随机数
            int x = i + rand() % (n - i);
            swap(nums, i, x);
        }
    }

    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
// @lc code=end

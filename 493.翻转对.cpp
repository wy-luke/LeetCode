/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
private:
    vector<int> tmp;
    int res = 0;

public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        tmp.resize(n);
        sort(nums, 0, n - 1);
        return res;
    }
    
    void sort(vector<int> &nums, int lo, int hi) {
        if (lo >= hi) return;

        int mid = lo + (hi - lo) / 2;
        sort(nums, lo, mid);
        sort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }

    void merge(vector<int> &nums, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; ++i) {
            tmp[i] = nums[i];
        }

        // 维护区间[mid+1, end)，注意左闭右开，使区间初始为空，每有一个数满足条件，end++，使区间元素数+1
        // 小技巧，把 end 定义在 for 循环外面，使每次循环 end 不会退化至初始值，从而优化执行效率
        int end = mid + 1;
        for (int i = lo; i <= mid; ++i) {
            // 遍历从 mid + 1 到 hi 的元素，如果满足要求，则右移 end
            while (end <= hi && (long)nums[i] > (long)nums[end] * 2) {
                ++end;
            }
            // 区间 [mid+1, end) 的元素个数为 end - mid - 1
            res += end - mid - 1;
        }

        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; ++p) {
            if (i == mid + 1) {
                nums[p] = tmp[j++];
            } else if (j == hi + 1) {
                nums[p] = tmp[i++];
            } else if (tmp[i] > tmp[j]) {
                nums[p] = tmp[j++];
            } else {
                nums[p] = tmp[i++];
            }
        }
    }
};
// @lc code=end

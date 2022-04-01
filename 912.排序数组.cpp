/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
private:
    vector<int> tmp;

public:
    vector<int> sortArray(vector<int> &nums) {
        tmp.resize(nums.size());
        sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void sort(vector<int> &nums, int lo, int hi) {
        // 单个元素不用排序
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

        // 双指针
        int p = lo, q = mid + 1;
        for (int i = lo; i <= hi; ++i) {
            // 注意，nums 这里只用于存放排好序的结果，数值会被更新
            // 所以原值都要从 tmp 中获取
            if (p == mid + 1) {
                nums[i] = tmp[q++]; // 注意是从 tmp 中取值
            } else if (q == hi + 1) {
                nums[i] = tmp[p++];
                // 注意这里分为了 大于 和 小于等于 两种情况，只有前面的数大，才把先放后面的数
                // 而当前面的数 小于等于 后面的数时，都是先放 前面的数，可以保证稳定排序
            } else if (tmp[p] > tmp[q]) { // 注意是比较 tmp
                nums[i] = tmp[q++];
            } else {
                nums[i] = tmp[p++];
            }
        }
    }
};
// @lc code=end

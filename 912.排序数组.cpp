/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
// 快速排序
class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        // 随机打乱数组
        shuffle(nums);
        sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void sort(vector<int> &nums, int lo, int hi) {
        if (lo >= hi) return;

        int p = partition(nums, lo, hi);
        sort(nums, lo, p - 1);
        sort(nums, p + 1, hi);
    }

    int partition(vector<int> &nums, int lo, int hi) {
        int pivot = nums[lo];

        // 维护区间 [lo, i) <= pivot, (j, hi] > pivot
        // 初始化 [lo, i) 仅包含 lo 元素，(j, hi] 为空
        int i = lo + 1, j = hi;
        // 当 i > j 时结束循环，以保证区间 [lo, hi] 都被覆盖
        while (i <= j) {
            // 使用 < hi 是因为 hi 元素会由下面的 j 循环对比大小
            while (i < hi && nums[i] <= pivot) {
                i++;
                // 此 while 结束时恰好 nums[i] > pivot
            }
            // 使用 > lo 是因为 lo 元素就是 pivot，无须比较
            while (j > lo && nums[j] > pivot) {
                j--;
                // 此 while 结束时恰好 nums[j] <= pivot
            }
            // 此时 [lo, i) <= pivot && (j, hi] > pivot

            // i=j时交换没有意义，i>j 时已经遍历完毕，再 swap 就把排好序的打乱了
            if (i >= j) break;

            swap(nums, i, j);
        }
        // 把 lo 元素插入到左边区间的最右侧，即 j
        swap(nums, lo, j);
        return j;
    }

    void shuffle(vector<int> &nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // rand() % n 生成 [0, n) 即 [0, n-1] 范围的随机数
            // 这里生成 [i, n-1] 范围的随机数
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

// 归并排序
// class Solution {
// private:
//     vector<int> tmp;

// public:
//     vector<int> sortArray(vector<int> &nums) {
//         tmp.resize(nums.size());
//         sort(nums, 0, nums.size() - 1);
//         return nums;
//     }

//     void sort(vector<int> &nums, int lo, int hi) {
//         // 单个元素不用排序
//         if (lo >= hi) return;

//         int mid = lo + (hi - lo) / 2;
//         sort(nums, lo, mid);
//         sort(nums, mid + 1, hi);
//         merge(nums, lo, mid, hi);
//     }

//     void merge(vector<int> &nums, int lo, int mid, int hi) {
//         for (int i = lo; i <= hi; ++i) {
//             tmp[i] = nums[i];
//         }

//         // 双指针
//         int p = lo, q = mid + 1;
//         for (int i = lo; i <= hi; ++i) {
//             // 注意，nums 这里只用于存放排好序的结果，数值会被更新
//             // 所以原值都要从 tmp 中获取
//             if (p == mid + 1) {
//                 nums[i] = tmp[q++]; // 注意是从 tmp 中取值
//             } else if (q == hi + 1) {
//                 nums[i] = tmp[p++];
//                 // 注意这里分为了 大于 和 小于等于 两种情况，只有前面的数大，才把先放后面的数
//                 // 而当前面的数 小于等于 后面的数时，都是先放 前面的数，可以保证稳定排序
//             } else if (tmp[p] > tmp[q]) { // 注意是比较 tmp
//                 nums[i] = tmp[q++];
//             } else {
//                 nums[i] = tmp[p++];
//             }
//         }
//     }
// };
// @lc code=end

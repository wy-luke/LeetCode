// @before-stub-for-debug-begin
#include "commoncppproblem315.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
private:
    vector<pair<int, int>> tmp;
    vector<int> res;

public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();

        tmp.resize(n);
        res.resize(n);

        // 记录每个值和其对应的 index
        vector<pair<int, int>> valIndex;
        valIndex.reserve(n);
        for (int i = 0; i < n; ++i) {
            valIndex.emplace_back(nums[i], i);
        }

        sort(valIndex, 0, n - 1);

        return res;
    }

    // 归并排序
    void sort(vector<pair<int, int>> &valIndex, int lo, int hi) {
        // 单个元素不用排序
        if (lo >= hi) return;

        int mid = lo + (hi - lo) / 2;
        sort(valIndex, lo, mid);
        sort(valIndex, mid + 1, hi);
        merge(valIndex, lo, mid, hi);
    }

    void merge(vector<pair<int, int>> &valIndex, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; ++i) {
            tmp[i] = valIndex[i];
        }

        // 双指针
        int p = lo, q = mid + 1;
        for (int i = lo; i <= hi; ++i) {
            // 注意，nums 这里只用于存放排好序的结果，数值会被更新
            // 所以原值都要从 tmp 中获取
            if (p == mid + 1) {
                valIndex[i] = tmp[q++];
            } else if (q == hi + 1) {
                res[tmp[p].second] += q - mid - 1;
                valIndex[i] = tmp[p++];
                // 注意这里分为了 大于 和 小于等于 两种情况，只有前面的数大，才把先放后面的数
                // 而当前面的数 小于等于 后面的数时，都是先放 前面的数，可以保证稳定排序
            } else if (tmp[p].first > tmp[q].first) { // 注意是比较 tmp
                valIndex[i] = tmp[q++];
            } else {
                res[tmp[p].second] += q - mid - 1;
                valIndex[i] = tmp[p++];
            }
        }
    }
};
// @lc code=end

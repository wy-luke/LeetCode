/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    // 耗时和速度的单调递减函数
    int f(vector<int> &piles, int speed) {
        int hours = 0;
        for (int i : piles) {
            hours += i / speed;
            if (i % speed != 0) ++hours;
        }
        return hours;
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        // 定义最小值和最大值，区间为左闭右开 [ )，所以 right 要 +1
        int left = 1;
        int right = *max_element(piles.begin(), piles.end()) + 1;

        // 寻找左侧边界的二分查找，注意函数为单调递减
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f(piles, mid) > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

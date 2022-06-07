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
        for (int pile : piles) {
            // 向上取整
            hours += (pile + speed - 1) / speed;
        }
        return hours;
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        // 定义最小值和最大值
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        // 寻找左侧边界的二分查找，注意函数为单调递减
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (f(piles, mid) > h) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

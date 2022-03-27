/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    // days 关于 weight 的单调递减函数
    int f(vector<int> &weights, int weight) {
        int days = 0;
        int sum = 0;
        for (int i : weights) {
            sum += i;
            if (sum == weight) {
                sum = 0;
                days++;
            } else if (sum > weight) {
                sum = i;
                days++;
            }
        }
        return sum != 0 ? days + 1 : days;
    }

    int shipWithinDays(vector<int> &weights, int days) {
        // 最小值为最重的货物重量，否则永远无法完成运输
        int left = 0;
        // 最大值为所有货物的重量和，再大也是一天完成，注意区间为左闭右开 [ )，所以需要 +1
        int right = 1;
        for (int i : weights) {
            right += i;
            left = max(left, i);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f(weights, mid) > days) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

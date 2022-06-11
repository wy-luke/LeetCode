/*
 * @lc app=leetcode.cn id=1870 lang=cpp
 *
 * [1870] 准时到达的列车最小时速
 */

// @lc code=start
class Solution {
public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        int n = dist.size();
        // int 除 int，注意类型转换！
        if (n - 1 + (double)dist.back() / 1e7 > hour) return -1;
        // 找到速度 s 时的总用时
        auto totalTime = [&](int s) -> double {
            double sum = 0;
            for (int i = 0; i < n - 1; ++i) {
                sum += (dist[i] + s - 1) / s; // 向上取整
            }
            // int 除 int，注意类型转换！
            sum += (double)dist.back() / s;
            return sum;
        };
        int l = 1, r = 1e7;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (totalTime(mid) > hour) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
// @lc code=end

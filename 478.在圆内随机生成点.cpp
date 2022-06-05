/*
 * @lc app=leetcode.cn id=478 lang=cpp
 *
 * [478] 在圆内随机生成点
 */

// @lc code=start
class Solution {
public:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double r, xc, yc;
    Solution(double radius, double x_center, double y_center) : dis(0, 1), r(radius), xc(x_center), yc(y_center) {
    }

    vector<double> randPoint() {
        double l = sqrt(dis(gen) * r * r);
        double rad = dis(gen) * 2 * acos(-1.0);
        return {xc + l * cos(rad), yc + l * sin(rad)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

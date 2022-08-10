/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        // cnt统计x的个数,sum统计其他数之和,num用于记录当前的数字
        int cnt = 0, sum = 0, num = 0, sign = 1;
        int n = equation.size();
        for (int i = 0; i < n; ++i) {
            char c = equation[i];
            if (c == '+' || c == '-') {
                sum += sign * num;
                sign = c == '+' ? 1 : -1;
                num = 0;
            } else if (c == '=') {
                sum += sign * num;
                sign = 1;
                num = 0;
                sum = -sum;
                cnt = -cnt;
            } else if (c == 'x') {
                if (sign == 0) {
                    sign = 1;
                } else {
                    if (num != 0) {
                        cnt += sign * num;
                        num = 0;
                    } else {
                        cnt += sign;
                    }
                }
            } else {
                if (num == 0 && c == '0') {
                    sign = 0;
                }
                num = num * 10 + (c - '0');
            }

            if (i == n - 1) {
                sum += sign * num;
            }
        }
        if (cnt == 0) {
            return sum == 0 ? "Infinite solutions" : "No solution";
        } else {
            return "x=" + to_string(-sum / cnt);
        }
    }
};
// @lc code=end

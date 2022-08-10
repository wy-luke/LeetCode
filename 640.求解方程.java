/*
 * @lc app=leetcode.cn id=640 lang=java
 *
 * [640] 求解方程
 */

// @lc code=start
class Solution {
    public String solveEquation(String equation) {
        int cnt = 0, sum = 0, sign = 1, n = equation.length();
        char[] cs = equation.toCharArray();
        for (int i = 0; i < n;) {
            if (cs[i] == '+') {
                sign = 1;
                ++i;
            } else if (cs[i] == '-') {
                sign = -1;
                ++i;
            } else if (cs[i] == '=') {
                cnt = -cnt;
                sum = -sum;
                sign = 1;
                ++i;
            } else {
                int j = i;
                while (j < n && cs[j] != '+' && cs[j] != '-' && cs[j] != '=') {
                    ++j;
                }
                if (cs[j - 1] == 'x') {
                    cnt += sign * (j - i == 1 ? 1 : Integer.parseInt(equation.substring(i, j - 1)));
                } else {
                    sum += sign * Integer.parseInt(equation.substring(i, j));
                }
                i = j;
            }
        }
        if (cnt == 0) {
            return sum == 0 ? "Infinite solutions" : "No solution";
        } else {
            return "x=" + (-sum / cnt);
        }
    }
}
// @lc code=end

/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

// @lc code=start
class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> nums(4); // 记录数字，每四个数字代表两个分数，则进行一次计算
        int cnt = 0;         // 记录现存的有效数字个数
        int sign = 1, n = expression.size();
        string num; // 临时变量，用于记录每一个数字
        for (int i = 0; i < n; ++i) {
            char e = expression[i];
            if (isdigit(e)) num += e;
            if (!isdigit(e) || i == n - 1) {
                // 遇到符号时，只有当存在数字才记录
                // 如 -1，只遇到负号不做记录
                if (num != "") {
                    nums[cnt++] = sign * stoi(num); //记录
                    num = "", sign = 1;             // 归位
                    if (cnt == 4) {
                        pair<int, int> res = calculate(nums);
                        nums[0] = res.first, nums[1] = res.second;
                        cnt = 2;
                    }
                }
            }
            if (e == '-') sign = -1;
        }
        return to_string(nums[0]) + "/" + to_string(nums[1]);
    }

    pair<int, int> calculate(vector<int> nums) {
        int num1 = nums[0] * nums[3] + nums[2] * nums[1];
        int num2 = nums[1] * nums[3];
        // 求最大公约数记得加绝对值！！
        int d = gcd(abs(num1), abs(num2));
        return make_pair(num1 / d, num2 / d);
    }
    // gcd 算法！！！求最大公约数
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
// @lc code=end

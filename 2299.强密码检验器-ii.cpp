/*
 * @lc app=leetcode.cn id=2299 lang=cpp
 *
 * [2299] 强密码检验器 II
 */

// @lc code=start
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if (n < 8) return false;
        string s = "!@#$%^&*()-+";
        bool b2 = false, b3 = false, b4 = false, b5 = false, b6 = true;
        for (int i = 0; i < n; ++i) {
            if (!b2 && islower(password[i])) b2 = true;
            if (!b3 && isupper(password[i])) b3 = true;
            if (!b4 && isdigit(password[i])) b4 = true;
            if (!b5 && s.find(password[i]) != string::npos) b5 = true;
            if (i < n - 1 && password[i] == password[i + 1]) b6 = false;
        }
        return b2 && b3 && b4 && b5 && b6;
    }
};
// @lc code=end

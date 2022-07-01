/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) return memo[expression];
        int n = expression.size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            char c = expression[i];
            if (isdigit(c)) continue;
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            for (int l : left) {
                for (int r : right) {
                    if (c == '-') {
                        res.emplace_back(l - r);
                    } else if (c == '+') {
                        res.emplace_back(l + r);
                    } else {
                        res.emplace_back(l * r);
                    }
                }
            }
        }
        if (res.empty()) res.emplace_back(stoi(expression));
        memo[expression] = res;
        return res;
    }
};
// @lc code=end

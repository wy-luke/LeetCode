/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        // 差分数组
        vector<int> res(1001);
        // 记录最大目的地，用于减少第二个循环次数
        int maxEnd = 0;
        for (vector<int> &trip : trips) {
            // 不同于一般的差分数组，在目的地就直接下车，所以直接在目的地的index直接减去
            res[trip[1]] += trip[0];
            res[trip[2]] -= trip[0];
            maxEnd = max(maxEnd, trip[2]); // 更新 maxEnd
        }

        if (res[0] > capacity) return false;

        for (int i = 1; i < maxEnd; ++i) {
            res[i] += res[i - 1];
            if (res[i] > capacity) return false;
        }
        return true;
    }
};
// @lc code=end

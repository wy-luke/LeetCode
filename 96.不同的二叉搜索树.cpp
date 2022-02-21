/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        memo.resize(n + 1, vector<int>(n + 1, 0));
        return count(1, n);
    }
    
    int count(int start, int end) {
        if (end <= start) return 1;

        if (memo[start][end] != 0) return memo[start][end];

        int num = 0;
        for (int i = start; i <= end; ++i) {
            num += count(start, i - 1) * count(i + 1, end);
        }
        memo[start][end] = num;
        return num;
    }

private:
    vector<vector<int>> memo;
};
// @lc code=end

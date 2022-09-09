/*
 * @lc app=leetcode.cn id=1598 lang=cpp
 *
 * [1598] 文件夹操作日志搜集器
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<string> &logs) {
        int depth = 0;
        for (string log : logs) {
            if (log == "../") {
                if (depth != 0) {
                    --depth;
                }
            } else if (log != "./") {
                ++depth;
            }
        }
        return depth;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */

// @lc code=start
class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        // 使用稳定排序
        stable_sort(logs.begin(), logs.end(), [](const string &a, const string &b) {
            int i = a.find(" ") + 1, j = b.find(" ") + 1;
            bool digit1 = isdigit(a[i]), digit2 = isdigit(b[j]);
            // 如果都为数字，则不排序
            if (digit1 && digit2) return false;
            // 如果都为字母
            if (!digit1 && !digit2) {
                string p = a.substr(i);
                string q = b.substr(j);
                // 先比较日志
                if (p != q) return p < q;
                // 如果日志相同，再比较标识符
                return a < b;
            }
            // 如果一个数字一个字母，把字母放在前面
            return digit1 ? false : true;
        });
        return logs;
    }
};
// @lc code=end

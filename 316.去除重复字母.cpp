/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 用于记录最终结果，只存放不重复的字母，即单调栈，这里直接用 string
        string res;
        // 用于记录结果中已经存放的字母
        vector<bool> inRes(26);

        // 用于记录 s 中每个字母的个数
        vector<int> charNum(26);
        // 统计字母个数
        for (char i : s) {
            ++charNum[i - 'a'];
        }

        for (char i : s) {
            // 每遍历一个，个数减一，这里 num 代表 s 中还剩余（未遍历）的某个字母的个数
            --charNum[i - 'a'];

            // res 经过下面的维护，已经能够最大程度满足单调，即字典序
            // 所以如果 res 中已有某个字母，则直接跳过
            if (inRes[i - 'a']) continue;

            // 对 res 中不满足字典序的，pop 出去
            while (!res.empty() && i < res.back()) {
                // 若某个字母在未遍历的 s 中没有剩余，则不能 pop
                // 因为题目说是去除重复字母，若 pop 则将完全将该字母去除，而不是去除重复
                if (charNum[res.back() - 'a'] == 0) break;
                // pop 后 res 将没有该字母，置为 false
                inRes[res.back() - 'a'] = false;
                res.pop_back();
            }
            // pop 完后插入字符
            res.push_back(i);
            inRes[i - 'a'] = true;
        }
        return res;
    }
};
// @lc code=end

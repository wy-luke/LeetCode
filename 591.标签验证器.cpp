/*
 * @lc app=leetcode.cn id=591 lang=cpp
 *
 * [591] 标签验证器
 */

// @lc code=start
class Solution {
public:
    bool isValid(string code) {
        int n = code.size();

        int i = 0;
        stack<string> stk;
        while (i < n) {
            if (code[i] == '<') {
                // 防止后面的判断过界
                if (i == n - 1) return false;

                if (code[i + 1] == '!') {
                    // 此时 stk 不能为空，并且字符串要为 ![CDATA[
                    if (stk.empty() || code.substr(i + 2, 7) != "[CDATA[") return false;
                    int j = code.find("]]>", i + 9);
                    // 没找到
                    if (j == string::npos) return false;
                    // 后移 i
                    i = j + 3;
                } else if (code[i + 1] == '/') {
                    // 找 >
                    int j = code.find(">", i + 2);
                    // 没找到
                    if (j == string::npos) return false;
                    // 此时 stk 不能为空，并且 tagname 要和 stk.top 匹配，否则 false
                    if (stk.empty() || stk.top() != code.substr(i + 2, j - i - 2)) return false;
                    // 出栈
                    stk.pop();
                    i = j + 1;
                    if (stk.empty() && i != n) return false;
                } else {
                    int j = code.find(">", i + 1);
                    if (j == string::npos) return false;
                    // 判断tagname 长度
                    if (j - i - 1 > 9 || j - i - 1 == 0) return false;
                    string tagname = code.substr(i + 1, j - i - 1);
                    // 判断 tagname 是否全大写
                    if (!all_of(tagname.begin(), tagname.end(), [](unsigned char c) { return isupper(c); })) {
                        return false;
                    }
                    stk.emplace(tagname);
                    i = j + 1;
                }
            } else {
                if (stk.empty()) return false;
                ++i;
            }
        }
        return stk.empty();
    }
};
// @lc code=end

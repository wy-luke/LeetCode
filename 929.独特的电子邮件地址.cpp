/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> st;
        int res = 0;
        for (string &s : emails) {
            bool skip = false;
            string tmp = "";
            for (int i = 0; i < s.size(); ++i) {
                char c = s[i];
                if (c == '@') {
                    tmp += s.substr(i);
                    break;
                } else if (c == '+') {
                    skip = true;
                } else if (!skip && c != '.') {
                    tmp += c;
                }
            }
            if (st.count(tmp) == 0) ++res;
            st.emplace(tmp);
        }
        return res;
    }
};
// @lc code=end

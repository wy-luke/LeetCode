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
        for (string &email : emails) {
            string tmp;
            for (char c : email) {
                if (c == '@' || c == '+') {
                    break;
                }
                if (c != '.') {
                    tmp += c;
                }
            }
            st.emplace(tmp + email.substr(email.find('@')));
        }
        return st.size();
    }
};
// @lc code=end

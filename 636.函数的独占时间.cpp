/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] 函数的独占时间
 */

// @lc code=start
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        // 栈内存放 start 时间 与 其包含的其他函数区间长度
        // 在日志正确的前提下，遇到一个 end，栈顶就是对应的 start，所以无需记录标识符
        stack<pair<int, int>> st;
        vector<int> res(n, 0);
        for (string &s : logs) {
            int first = s.find_first_of(":");
            int second = s.find_last_of(":");

            if (second - first == 6) {
                // 为 start 时
                st.emplace(stoi(s.substr(second + 1)), 0);
            } else {
                // 为 end 时
                int id = stoi(s.substr(0, first));
                int endTime = stoi(s.substr(second + 1));
                auto p = st.top();
                st.pop();
                int len = endTime - p.first + 1;
                // 减去其包含的其他函数区间长度
                res[id] += len - p.second;
                // 如果此时栈内不为空，则说明存在上一层函数
                // 然后记录该层时间，在计算上一层时间时，减去该时间
                if (!st.empty()) {
                    st.top().second += len;
                }
            }
        }
        return res;
    }
};
// @lc code=end

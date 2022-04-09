/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        // 记录 deadends 和 visited
        unordered_set<string> st;
        for (string i : deadends) {
            st.emplace(i);
        }
        // 这里主要用来避免 0000 为 dead
        if (st.count("0000")) return -1;

        int step = 0;
        queue<string> q;
        q.emplace("0000");
        // 加入到 queue 的即为已 visit
        st.emplace("0000");
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string cur = q.front();
                q.pop();
                
                if (cur == target) return step;

                // 对每个节点，有 2+2+2+2 = 8 个相邻节点
                for (int j = 0; j < 4; ++j) {
                    string s = plusOne(cur, j);
                    if (!st.count(s)) {
                        q.emplace(s);
                        st.emplace(s);
                    }

                    s = minusOne(cur, j);
                    if (!st.count(s)) {
                        q.emplace(s);
                        st.emplace(s);
                    }
                }
            }
            ++step;
        }
        return -1;
    }

    string plusOne(string s, int i) {
        if (s[i] == '9') {
            s[i] = '0';
        } else {
            ++s[i];
        }
        return s;
    }
    string minusOne(string s, int i) {
        if (s[i] == '0') {
            s[i] = '9';
        } else {
            --s[i];
        }
        return s;
    }
};
// @lc code=end

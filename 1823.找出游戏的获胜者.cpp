/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        // 这里题目说明 k<=n 所以无需取余
        // 如果取余，注意 n % n = 0
        // if (k % n == 0)
        //     k = n;
        // else
        //     k = k % n;

        //  为方便取模，调成下标从 0 开始！！！记得返回时归位
        //  如果从 1 开始，n % n = 0，第 n 个数取模成了 0
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            st.emplace(i);
        }

        int cur = 0;
        while (st.size() != 1) {
            int count = 0;
            while (count < k) {
                if (st.count(cur % n) != 0) {
                    ++count;
                }
                ++cur;
            }
            st.erase((cur - 1) % n);
            while (st.count(cur % n) == 0)
                ++cur;
        }
        return *st.begin() + 1;

        // 下面为直接用 queue 模拟的解法，实现更简单一些
        // queue<int> q;
        // for (int i = 1; i <= n; ++i) {
        //     q.emplace(i);
        // }
        // while (q.size() != 1) {
        //     for (int i = 1; i < k; ++i) {
        //         q.emplace(q.front());
        //         q.pop();
        //     }
        //     q.pop();
        // }
        // return q.front();
    }
};
// @lc code=end

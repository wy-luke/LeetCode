/*
 * @lc app=leetcode.cn id=1898 lang=cpp
 *
 * [1898] 可移除字符的最大数目
 */

// @lc code=start
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int> &removable) {
        int ns = s.size(), np = p.size(), nr = removable.size();
        auto check = [&](int k) -> bool {
            unordered_set<int> st;
            for (int i = 0; i < k; ++i) {
                st.emplace(removable[i]);
            }
            int idx = 0;
            for (int i = 0; i < ns; ++i) {
                if (st.count(i)) continue;
                if (s[i] == p[idx]) ++idx;
                if (idx == np) return true;
            }
            return false;
        };
        int l = 0, r = nr;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid)) {
                // 最后的 l 是第一个 check 为 false 的，所以最终结果是 l-1
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};
// @lc code=end

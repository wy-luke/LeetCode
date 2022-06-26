/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
class Solution {
private:
    // 将 黑名单数字 映射到 正常数字
    unordered_map<int, int> mp;
    // 记录除去黑名单后的数字个数
    int sz;

public:
    Solution(int n, vector<int> &blacklist) {
        sz = n - blacklist.size();
        for (int b : blacklist) {
            mp[b] = b;
        }
        int i = sz;
        for (int b : blacklist) {
            if (b < sz) {
                while (mp.count(i)) {
                    ++i;
                }
                mp[b] = i++;
            }
        }
    }

    int pick() {
        int rnd = rand() % sz;
        return mp.count(rnd) ? mp[rnd] : rnd;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

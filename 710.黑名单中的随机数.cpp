/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
class Solution {
private:
    // 哈希表记录 数字 -> index, 用于将 黑名单数字 映射到 正常数字
    unordered_map<int, int> mp;
    // 记录除去黑名单后的数字个数
    int sz;

public:
    Solution(int n, vector<int> &blacklist) {
        sz = n - blacklist.size();

        for (int i : blacklist) {
            mp.emplace(i, i);
        }

        int right = n - 1;
        for (int i : blacklist) {
            if (i >= sz) continue;

            // 如果 right 在 blacklist 中，直接左移，直到找到非黑名单数字
            while (mp.count(right) != 0) {
                right--;
            }
            // 将 黑名单数字 映射到 正常数字
            mp[i] = right;
            right--;
        }
    }

    int pick() {
        int x = rand() % sz;
        // 如果随机数 x 为黑名单数字，则映射到正常数字
        if (mp.count(x) != 0) return mp[x];
        return x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

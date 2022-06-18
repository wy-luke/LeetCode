/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        // 设 spell 为 x，potion 为 y
        // x*y>=success 等价于 y>=⌈success/x⌉ 就等价于 y>(success−1​)/x
        // ⌈success/x⌉ = (success+x-1)/x = (success-1)/x+1 > (success−1​)/x
        unordered_map<int, int> mp;
        vector<int> res;
        res.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (mp.count(spells[i])) {
                res.emplace_back(mp[spells[i]]);
            } else {
                int cnt = potions.end() - upper_bound(potions.begin(), potions.end(), (success - 1) / spells[i]);
                res.emplace_back(cnt);
                mp[spells[i]] = cnt;
            }
        }
        return res;
    }
};
// @lc code=end

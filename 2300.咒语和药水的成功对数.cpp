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

        auto getCnt = [&](int spell) -> int {
            int l = 0, r = m;
            while (l < r) {
                int mid = l + ((r - l) >> 1);
                if ((long long)spell * potions[mid] < success) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return m - l;
        };
        unordered_map<int, int> mp;
        vector<int> res;
        res.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (mp.count(spells[i])) {
                res.emplace_back(mp[spells[i]]);
            } else {
                int cnt = getCnt(spells[i]);
                res.emplace_back(cnt);
                mp[spells[i]] = cnt;
            }
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int res = 0, pre = 0;
        for (int i : nums) {
            pre += i; // 到 i 的前缀和

            // 从 map 中查找是否包含 pre - k，包含则加上个数
            if (mp.count(pre - k) != 0) {
                res += mp[pre - k];
            }

            mp[pre]++;
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> mp;
        int idx = 1;
        for (int i : tmp) {
            if (!mp.count(i)) mp[i] = idx++;
        }
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
// @lc code=end

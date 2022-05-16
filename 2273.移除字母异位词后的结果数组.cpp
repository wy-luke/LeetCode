/*
 * @lc app=leetcode.cn id=2273 lang=cpp
 *
 * [2273] 移除字母异位词后的结果数组
 */

// @lc code=start
class Solution {
public:
    vector<string> removeAnagrams(vector<string> &words) {
        int n = words.size();
        vector<string> res;
        res.reserve(n);
        string pre = "";
        for (int i = 0; i < n; ++i) {
            string tmp = words[i];
            sort(tmp.begin(), tmp.end());
            if (tmp != pre) {
                res.emplace_back(words[i]);
                pre = tmp;
            }
        }
        return res;
    }
};
// @lc code=end

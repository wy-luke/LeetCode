/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */

// @lc code=start
class Solution {
public:
    string reformat(string s) {
        vector<char> nums, letters;
        for (char &c : s) {
            if (isdigit(c)) {
                nums.emplace_back(c);
            } else {
                letters.emplace_back(c);
            }
        }
        int a = nums.size(), b = letters.size();
        if (abs(a - b) > 1) {
            return "";
        }
        string ans;
        int p = 0, q = 0;
        if (b > a) {
            ans += letters[q++];
        }
        while (p < a && q < b) {
            ans += nums[p++];
            ans += letters[q++];
        }
        if (p < a) ans += nums[p];
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();

        // num, idx 记录每位数字最右边出现的下标
        map<int, int> mp;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            nums.push_back(x);
            mp[x] = i;
        }
        sort(nums.begin(), nums.end(), greater());
        for (int i = 0; i < n; ++i) {
            // 当某一位上的数字不是该位置的最大值时，和最大值交换
            if (s[i] - '0' < nums[i]) {
                // 把 s[i] 和 最右边出现的 num[i] 交换
                // 这样可以保证小数字 s[i] 出现在最右边，即结果最大
                swap(s[i], s[mp[nums[i]]]);
                break;
            }
        }
        return stoi(s);
    }
};
// @lc code=end
